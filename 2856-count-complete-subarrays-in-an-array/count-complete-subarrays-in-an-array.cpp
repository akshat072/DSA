class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> totalSet(nums.begin(), nums.end());
        int totalDistinct = totalSet.size();

        int left = 0, res = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;

            while (freq.size() == totalDistinct) {
                res += (n - right); 
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
        }

        return res;
    }
};
