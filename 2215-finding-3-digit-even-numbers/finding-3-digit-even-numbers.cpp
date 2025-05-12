class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        vector<int> res;

        for (int num = 100; num <= 999; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> tempFreq = freq;
            if (tempFreq[a]-- > 0 && tempFreq[b]-- > 0 && tempFreq[c]-- > 0) {
                res.push_back(num);
            }
        }

        return res;
    }
};
