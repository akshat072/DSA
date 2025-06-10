class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<int> odd_freqs, even_freqs;
        for (auto& [ch, f] : freq) {
            if (f % 2 == 1) odd_freqs.push_back(f);
            else even_freqs.push_back(f);
        }

        // Constraints guarantee at least one odd and one even frequency
        int max_odd = *max_element(odd_freqs.begin(), odd_freqs.end());
        int min_even = *min_element(even_freqs.begin(), even_freqs.end());
        return max_odd - min_even;
    }
};