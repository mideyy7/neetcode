class Solution {
public:
    int rob(vector<int>& nums) {
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int j = 2; j < nums.size(); ++j) {
            dp[j] = max(dp[j - 1], nums[j] + dp[j - 2]);
        }
        return dp[nums.size() - 1];
        
    }


};
