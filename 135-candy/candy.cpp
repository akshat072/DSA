class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Step 1: Give each child at least 1 candy

        // Step 2: Traverse from left to right
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Traverse from right to left
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum all candies
        int total = 0;
        for (int c : candies) {
            total += c;
        }

        return total;
    }
};