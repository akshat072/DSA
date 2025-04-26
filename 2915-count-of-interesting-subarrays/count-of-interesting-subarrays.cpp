class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> prefixFreq;
        prefixFreq[0] = 1; // Initial prefix mod value
        long long result = 0;
        int prefixMod = 0;

        for (int num : nums) {
            if (num % modulo == k)
                prefixMod = (prefixMod + 1) % modulo;
            else
                prefixMod = prefixMod % modulo;

            // Find needed mod that satisfies (currMod - neededMod + modulo) % modulo == k
            int needed = (prefixMod - k + modulo) % modulo;
            result += prefixFreq[needed];

            // Update frequency of current prefixMod
            prefixFreq[prefixMod]++;
        }

        return result;
    }
};