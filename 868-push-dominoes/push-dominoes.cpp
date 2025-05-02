class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int left = -1;  // Last 'L' index
        int right = -1; // Last 'R' index

        for (int i = 0; i <= n; ++i) {
            char c = (i < n) ? dominoes[i] : 'R'; 
            if (c == 'L') {
                if (right == -1) {

                    for (int j = i - 1; j > left; --j) {
                        result[j] = 'L';
                    }
                } else {
                    int l = right + 1, r = i - 1;
                    while (l < r) {
                        result[l++] = 'R';
                        result[r--] = 'L';
                    }
                    right = -1;
                }
                left = i;
            } else if (c == 'R') {
                if (right != -1) {
                    for (int j = right + 1; j < i; ++j) {
                        result[j] = 'R';
                    }
                }
                right = i;
            }
        }

        return result;
    }
};