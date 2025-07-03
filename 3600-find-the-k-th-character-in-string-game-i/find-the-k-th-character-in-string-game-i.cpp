class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while (word.size() < k) {
            string next = "";
            for (char c : word) {
                char nextChar = (c == 'z') ? 'a' : c + 1;
                next += nextChar;
            }
            word += next;
        }

        return word[k - 1]; // 1-indexed to 0-indexed
    }
};