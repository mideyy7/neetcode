class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> current;
        vector<vector<int>> result;
        solve(nums, current, used, result);
        return result;
    }

    void solve(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            solve(nums, current, used, result);
            current.pop_back();
            used[i] = false;
        }
    }
};
