class Solution {
    using ll = long long;
public:
    long long countSubarrays(const vector<int>& nums, long long k) {
        ll n = nums.size();
        ll left = 0, right = 0;   
        ll sum = 0;               
        ll count = 0;

        while (left < n) {
            while (right<n and (sum+nums[right])*(right-left+1) < k)
                sum += nums[right++];

            count += right - left; 

           
            if (right == left)
                right++;
            else 
                sum -= nums[left];
            
            left++;
        }
        return count;
    }
};