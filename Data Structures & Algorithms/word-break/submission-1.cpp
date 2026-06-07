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
        vector<int> dp(s.size() + 1, -1);
        return solve(s, wordDict, 0, dp);
    }

    bool solve(string s, vector<string>& w_dict, int index, vector<int>& dp) {
        if (index >= s.size()) return true;
        if (dp[index] != -1) return dp[index];
        for(string& word: w_dict) {
            if (s.substr(index, word.size()) == word) {
                bool result = solve(s, w_dict, index + word.size(), dp);
                if (result) return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
};
