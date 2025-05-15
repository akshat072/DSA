class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            if (result.empty() || groups[i] != groups[result.size() - 1 == 0 ? 0 : i - 1]) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
