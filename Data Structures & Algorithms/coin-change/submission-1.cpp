class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int result = solve(coins, amount, 0, dp);
        if (result == INT_MAX) return -1;
        return result;
        // sort(coins.begin(), coins.end(), [](int a, int b) {
        //     return a > b;
        // });
        // for (int coin: coins) {
        //     while (coin <= amount) {
        //         amount -= coin;
        //         count += 1;
        //         if (amount == 0) return count;
        //     }
        // }
        // return -1;
        
    }
    int solve(vector<int>& coins, int target, int index, vector<vector<int>>& dp) {
        if (target == 0) return 0;
        if (index == coins.size() || target < 0) return INT_MAX;
        if (dp[index][target] != -1) return dp[index][target];

        int take = solve(coins, target - coins[index], index, dp);
        if (take != INT_MAX) take += 1;
        int not_take = solve(coins, target, index + 1, dp);
        return dp[index][target] = min(take, not_take);
    }
};
