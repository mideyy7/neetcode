class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> slice1(nums.begin() + 1, nums.end());   
        vector<int> slice2(nums.begin(), nums.end() - 1); 
        vector<int> dp(nums.size(), -1);
        int result = max(solve(0, slice1, dp), solve(0, slice2, dp));
        return result;


    }
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if(n >= nums.size()) {
            return 0;
        }
        if (dp[n] != -1) return dp[n];
        return dp[n] = max(nums[n] + solve(n + 2, nums, dp), solve(n + 1, nums, dp));
    }
};
