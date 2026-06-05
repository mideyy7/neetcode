class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num: nums) {
            total += num;
        }
        if (total % 2 != 0) return false;
        int target = total / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(nums, target, 0, dp);       
    }

    bool solve(vector<int>& nums, int target, int index, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (target < 0 || index >= nums.size()) return false;
        if (dp[index][target] != -1) return dp[index][target];
        bool pick = solve(nums, target - nums[index], index + 1, dp);
        bool not_pick = solve(nums, target, index + 1, dp);
        return dp[index][target] = pick || not_pick;
    }
};
