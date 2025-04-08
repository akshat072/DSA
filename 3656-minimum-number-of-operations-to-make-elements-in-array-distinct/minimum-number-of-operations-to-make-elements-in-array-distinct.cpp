
class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        int n = nums.size();

        for (int i = n - 1; i >= 0; --i) {
            if (seen.find(nums[i]) != seen.end()) {
                return std::ceil((i + 1) / 3.0);
            }
            seen.insert(nums[i]);
        }

        return 0;
    }
};
