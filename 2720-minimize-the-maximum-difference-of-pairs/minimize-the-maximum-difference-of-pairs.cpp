class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums.front();
        int ans = right;

        auto canFormPairs = [&](int maxDiff) {
            int count = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] - nums[i - 1] <= maxDiff) {
                    ++count;
                    ++i; // skip next to avoid reuse
                }
            }
            return count >= p;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};