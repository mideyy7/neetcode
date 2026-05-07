class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int pointer = 0;
        string result = "";
        while (pointer < word1.size() || pointer < word2.size()) {
                if (pointer < word1.size()) {
                    result += word1[pointer];
                }
                if (pointer < word2.size()) {
                    result += word2[pointer];
                }
                pointer++;
        }
        return result;
    }
};