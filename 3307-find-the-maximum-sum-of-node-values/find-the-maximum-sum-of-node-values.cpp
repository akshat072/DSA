class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = 0;
        int minDiff = INT_MAX;
        int countGain = 0;

        for (int num : nums) {
            int xorVal = num ^ k;
            if (xorVal > num) {
                total += xorVal;
                countGain++;
            } else {
                total += num;
            }
            minDiff = min(minDiff, abs(xorVal - num));
        }

        // If we have an even number of gains, we can keep them all
        if (countGain % 2 == 0) {
            return total;
        }

        // Otherwise, subtract the smallest difference (undo one gain)
        return total - minDiff;
    }
};