class Solution {
public:
    int climbStairs(int n) {

        /*
        base case is if n == 0: return 1
        if n < 0: return 0 as this is not a valid path
        solve(n - 1) + solve(n - 2)
        */

        vector<int>dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        // return solve(n, dp);
        
    }

    int solve (int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
};
