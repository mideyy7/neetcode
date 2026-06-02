class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> slice1(nums.begin() + 1, nums.end());   
        vector<int> slice2(nums.begin(), nums.end() - 1); 
        vector<int> dp1(slice1.size(), -1);
        vector<int> dp2(slice2.size(), -1);
        int result = max(solve(0, slice1, dp1), solve(0, slice2, dp2));
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
