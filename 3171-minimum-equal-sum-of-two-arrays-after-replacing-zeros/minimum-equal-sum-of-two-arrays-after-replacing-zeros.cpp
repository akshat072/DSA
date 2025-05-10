
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int zeros1 = 0;
        int zeros2 = 0;

        for (int num : nums1) {
            if (num == 0) {
                zeros1++;
            }
        }
        for (int num : nums2) {
            if (num == 0) {
                zeros2++;
            }
        }

        if (zeros1 == 0 && zeros2 == 0) {
            return (sum1 == sum2) ? sum1 : -1;
        }

        if (zeros1 == 0) {
            if (sum1 < sum2 + zeros2) {
                return -1;
            }
            return sum1;
        }

        if (zeros2 == 0) {
            if (sum2 < sum1 + zeros1) {
                return -1;
            }
            return sum2;
        }

        long long min_sum1 = sum1 + zeros1;
        long long min_sum2 = sum2 + zeros2;

        if (min_sum1 == min_sum2) {
            return min_sum1;
        } else if (min_sum1 > min_sum2) {
            return min_sum1;
        } else {
            return min_sum2;
        }
    }
};