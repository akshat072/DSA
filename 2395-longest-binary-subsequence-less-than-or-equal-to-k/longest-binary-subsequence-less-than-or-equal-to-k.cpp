class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int zeros = 0;

        // Count all zeros first — always safe
        for (char ch : s) {
            if (ch == '0') zeros++;
        }

        int n = s.length();
        long long value = 0;
        int power = 0;

        // Start from the end (LSB)
        for (int i = n - 1; i >= 0 && power < 31; i--) {
            if (s[i] == '1') {
                value += (1LL << power);
                if (value <= k) {
                    count++;
                } else {
                    break;
                }
                power++;
            } else {
                power++;
            }
        }

        return count + zeros;
    }
};