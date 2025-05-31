class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        
        auto getPosition = [&](int num) -> pair<int, int> {
            int r = (num - 1) / n;
            int c = (num - 1) % n;
            if (r % 2 == 1) c = n - 1 - c; 
            return {n - 1 - r, c}; 
        };
        
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();
            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n) break;

                auto [r, c] = getPosition(next);
                if (board[r][c] != -1) {
                    next = board[r][c]; 
                }

                if (next == n * n) return moves + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1; 
    }
};
