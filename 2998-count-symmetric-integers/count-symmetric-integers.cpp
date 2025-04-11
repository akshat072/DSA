class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; ++num) {
            int digits[10], len = 0, temp = num;

            while (temp) {
                digits[len++] = temp % 10;
                temp /= 10;
            }

            if (len % 2 != 0) continue; 

            int half = len / 2;
            int sum1 = 0, sum2 = 0;

            for (int i = 0; i < half; ++i)
                sum1 += digits[i]; 

            for (int i = half; i < len; ++i)
                sum2 += digits[i]; 

            if (sum1 == sum2) count++;
        }

        return count;
    }
};
