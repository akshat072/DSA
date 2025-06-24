class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;
        vector<bool> visited(n, false);  // To avoid duplicates

        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; ++j) {
                    if (!visited[j]) {
                        visited[j] = true;
                        result.push_back(j);
                    }
                }
            }
        }

        return result;
    }
};