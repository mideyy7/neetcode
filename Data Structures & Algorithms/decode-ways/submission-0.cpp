class Solution {
public:
    int numDecodings(string s) {
        /*
        take 1 or take 2
        take 1 if it is not 0
        take 2 if it is less than 27 and greater than 9
        */
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp); 
    }

    int solve(string& s, int index, vector<int>& dp) {
        if (index == s.size()) return 1;
        if (dp[index] != -1) return dp[index];
        int result = 0;
        int value = s[index] - '0';
        if (value >= 1 && value <= 9) {
            result += solve(s, index + 1, dp);
        }
        if (index + 1 < s.size()) {
            int word = stoi(s.substr(index, 2));
            if (word >= 10 && word <= 26) {
            result += solve(s, index + 2, dp);
        }
        return dp[index] = result;
    }
    }
};
