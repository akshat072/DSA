class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end()); // Step 1: Find max element
        long long res = 0;
        int left = 0, count = 0;

        // Step 2: Sliding window
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == maxVal) count++;

            while (count >= k) {
                res += (nums.size() - right); // All subarrays ending at or after right
                if (nums[left] == maxVal) count--;
                left++;
            }
        }
        return res;
    }
};
