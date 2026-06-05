class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);

    }

    int solve (int n , vector<int>& dp) {
        if (n == 2) return 1;
        if (dp[n] != -1) return dp[n];
        int result = 0;
        for (int i = 1; i <= n / 2; ++i) {
            int value = max(i * (n - i), i * solve(n - i, dp));
            result = max(result, value);
        }
        dp[n] = result;
        return result;
    }

};