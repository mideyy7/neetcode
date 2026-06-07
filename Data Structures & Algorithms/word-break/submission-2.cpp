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
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.size(); ++i) {
            for (string& word: wordDict) {
                int start_index = i - word.size();
                if (start_index >= 0 && dp[start_index] && s.substr(start_index,word.size()) == word) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];

        // return solve(s, wordDict, 0, dp);
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
