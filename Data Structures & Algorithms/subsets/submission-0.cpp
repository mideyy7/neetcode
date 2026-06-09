class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        solve(nums, 0, current, result);
        return result;
    }

    void solve(vector<int>& nums, int index, vector<int>& current ,vector<vector<int>>& result) {
        if (index >= nums.size()) {
            result.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        solve(nums, index + 1, current, result);
        current.pop_back();
        solve(nums, index + 1, current, result);
    }
};
