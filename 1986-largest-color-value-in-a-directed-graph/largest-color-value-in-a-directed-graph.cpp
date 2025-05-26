class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        // Build graph and indegree count
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // Topological sort
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                q.push(i);

        vector<vector<int>> dp(n, vector<int>(26, 0));
        int visited = 0, res = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited++;

            int colorIdx = colors[node] - 'a';
            dp[node][colorIdx]++;
            res = max(res, dp[node][colorIdx]);

            for (int nei : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    dp[nei][c] = max(dp[nei][c], dp[node][c]);
                }
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return (visited == n) ? res : -1;
    }
};