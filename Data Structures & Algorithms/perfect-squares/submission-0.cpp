class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
    int solve(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        int result = INT_MAX;
        for (int s = 1; s * s <= n; ++s) {
            int value = 1 + numSquares(n - (s * s));
            result = min(result, value);
        }
        return dp[n] = result;
    }
};