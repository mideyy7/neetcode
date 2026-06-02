class Solution {
public:
    int rob(vector<int>& nums) {
        return dfs(0, nums);
        
    }
    int dfs(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }
        return max(nums[i] + dfs(i + 2, nums), dfs(i + 1, nums));
    }
};
