class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        solve(candidates, target, 0, current, result);
        return result;    
    }

    void solve(vector<int>& candidates, int target, int index, vector<int> current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || index >= candidates.size()) return;

        current.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index + 1, current, result);
        current.pop_back();
        int next = index + 1;
        while (next < candidates.size() && candidates[next] == candidates[index]) {
            next += 1;
        }
        solve(candidates, target, next, current, result);

    }
};
