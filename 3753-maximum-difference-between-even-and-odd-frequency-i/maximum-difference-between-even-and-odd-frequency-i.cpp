class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        
        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }
        
        int maxDiff = INT_MIN;
        vector<int> oddFreq, evenFreq;

        for (auto& [ch, count] : freq) {
            if (count % 2 == 1) {
                oddFreq.push_back(count);
            } else {
                evenFreq.push_back(count);
            }
        }

        // Find maximum difference between any odd freq and any even freq
        for (int odd : oddFreq) {
            for (int even : evenFreq) {
                maxDiff = max(maxDiff, odd - even);
            }
        }

        return maxDiff;
    }
};