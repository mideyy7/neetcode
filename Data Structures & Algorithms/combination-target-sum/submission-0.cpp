class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        vector<vector<int>> result;
        solve(nums, target, 0, current, result);
        return result;  
    }


    void solve(vector<int>& nums, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || index >= nums.size()) return;
        current.push_back(nums[index]);
        solve(nums, target - nums[index], index , current, result);
        current.pop_back();
        solve(nums, target, index + 1, current, result);
    }
};
