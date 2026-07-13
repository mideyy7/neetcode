class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> v(nums.size(), false);
        vector<int> current;
        vector<vector<int>> result;
        solve(nums, v, current, result);
        return result;
    }

    void solve(vector<int>& nums, vector<bool>& v, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (v[i]) continue;
            v[i] = true;
            current.push_back(nums[i]);
            solve(nums, v,current, result);
            current.pop_back();
            v[i] = false;
        }
    }
};
