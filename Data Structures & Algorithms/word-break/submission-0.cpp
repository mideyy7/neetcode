class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        if i >= word.length: return true
        for word in dict: 
            if (s[i: word.lenght()] == word): 
                if solve(i + word.length()): return true
        return false


        s="applepenapple"
        wordDict=["apple","pen","ape"]

        */
        return solve(s, wordDict, 0);
    }

    bool solve(string s, vector<string>& w_dict, int index) {
        if (index >= s.size()) return true;
        for(string& word: w_dict) {
            if (s.substr(index, word.size()) == word) {
                bool result = solve(s, w_dict, index + word.size());
                if (result) return true;
            }
        }
        return false;
    }
};
