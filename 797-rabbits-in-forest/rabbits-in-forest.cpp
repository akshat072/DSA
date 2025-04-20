class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int res = 0;

        for (int a : answers) count[a]++;

        for (auto [k, v] : count) {
            int groupSize = k + 1;
            int groups = (v + groupSize - 1) / groupSize;
            res += groups * groupSize;
        }

        return res;
    }
};
