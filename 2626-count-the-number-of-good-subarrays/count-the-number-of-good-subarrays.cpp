class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        long long left = 0, pairCount = 0, result = 0;
        int n = nums.size();

        for (int right = 0; right < n; ++right) {
            pairCount += freq[nums[right]];
            freq[nums[right]]++;

            while (pairCount >= k) {
                result += n - right;  
                freq[nums[left]]--;
                pairCount -= freq[nums[left]];
                left++;
            }
        }

        return result;
    }
};
