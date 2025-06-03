class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> hasBox(n, false), hasKey(n, false), visited(n, false);
        queue<int> q;

        // Add initial boxes
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box]) q.push(box);
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (visited[curr]) continue;
            visited[curr] = true;

            // Collect candies
            totalCandies += candies[curr];

            // Use keys found in this box
            for (int k : keys[curr]) {
                hasKey[k] = true;
                if (hasBox[k] && !visited[k] && status[k] == 0) {
                    status[k] = 1;
                    q.push(k);
                }
            }

            // Add contained boxes
            for (int b : containedBoxes[curr]) {
                hasBox[b] = true;
                if ((status[b] || hasKey[b]) && !visited[b]) {
                    status[b] = 1;
                    q.push(b);
                }
            }
        }

        return totalCandies;
    }
};