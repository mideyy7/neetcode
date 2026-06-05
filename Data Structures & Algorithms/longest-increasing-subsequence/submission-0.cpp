class Solution {
public:
/*
Thoughts:
- take and not take
-init result = 0
- parameter: last_value\
- cases 
---if nums[index] <= last_value: return 0
---if index >= nums.size(): return 0
---take = 1 + solve(index + 1)
---nottake = 0 + isolve(index + 1)
result = max(take, not_take)
*/
    int solve(vector<int>& nums, int last_index, int index, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index][last_index + 1] != -1) return dp[index][last_index + 1];
        int take = 0;
        if (last_index == -1 || nums[index] > nums[last_index]) {
            take = 1 + solve(nums, index, index + 1, dp);
        }
        int not_take = solve(nums, last_index, index + 1, dp);
        return dp[index][last_index + 1] = max(take,  not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 2, -1));
        return solve(nums, -1, 0, dp);
    }
};
