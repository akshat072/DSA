class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> count(37, 0); 

        for (int i = 1; i <= n; ++i) {
            int sum = 0, x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            count[sum]++;
        }

        int maxSize = *max_element(count.begin(), count.end());
        return count_if(count.begin(), count.end(), [maxSize](int c) { return c == maxSize; });
    }
};
