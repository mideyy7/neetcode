class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        solve(nums, used, current, result);
        return result;
    }


    void solve(vector<int>& nums, vector<bool>& used, vector<int> & current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            solve(nums, used, current, result);
            used[i] = false;
            current.pop_back();
        }
    }
};