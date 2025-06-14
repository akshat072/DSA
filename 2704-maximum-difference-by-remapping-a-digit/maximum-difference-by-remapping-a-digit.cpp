class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxVal = num, minVal = num;

        for (char c : s) {
            if (c != '9') {
                string maxStr = s;
                for (char &ch : maxStr) {
                    if (ch == c) ch = '9';
                }
                maxVal = stoi(maxStr);
                break;
            }
        }

        for (char c : s) {
            if (c != '0') {
                string minStr = s;
                for (char &ch : minStr) {
                    if (ch == c) ch = '0';
                }
                minVal = stoi(minStr);
                break;
            }
        }

        return maxVal - minVal;
    }
};