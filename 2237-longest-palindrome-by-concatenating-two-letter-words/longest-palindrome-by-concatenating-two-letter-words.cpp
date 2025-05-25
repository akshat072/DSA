class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int length = 0;
        bool hasMiddle = false;

        for (const string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            
            if (freq[rev] > 0) {
                length += 4;
                freq[rev]--;
            } else {
                freq[word]++;
            }
        }

        for (const auto& [word, count] : freq) {
            if (word[0] == word[1] && count > 0) {
                hasMiddle = true;
                break;
            }
        }

        if (hasMiddle) length += 2;

        return length;
    }
};