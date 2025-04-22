class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAXN = 10001;
    vector<long long> fact = vector<long long>(MAXN);
    vector<long long> invFact = vector<long long>(MAXN);

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void precompute_factorials() {
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < MAXN; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        for (int i = 1; i < MAXN; ++i)
            invFact[i] = power(fact[i], MOD - 2);
    }

    long long comb(int a, int b) {
        if (b > a) return 0;
        return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        precompute_factorials();

        vector<vector<int>> divisors(maxValue + 1);
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = i * 2; j <= maxValue; j += i) {
                divisors[j].push_back(i);
            }
        }

        int maxLen = 14;
        vector<vector<long long>> dp(maxLen + 1, vector<long long>(maxValue + 1));

        for (int i = 1; i <= maxValue; ++i)
            dp[1][i] = 1;

        for (int len = 2; len <= maxLen; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int d : divisors[i]) {
                    dp[len][i] = (dp[len][i] + dp[len - 1][d]) % MOD;
                }
            }
        }

        long long result = 0;
        for (int len = 1; len <= maxLen; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                result = (result + dp[len][i] * comb(n - 1, len - 1) % MOD) % MOD;
            }
        }

        return (int)result;
    }
};