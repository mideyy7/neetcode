class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        solve(n, 0, 0, current, result);
        return result;

    }
        void solve(int n, int open, int closed, string& current, vector<string>& result) {
            if (closed == n) {
                result.push_back(current);
                return;
            }
            if (open < n) {
                current.push_back('(');
                solve(n, open + 1, closed, current, result);
                current.pop_back();
                //remove back of current
            }
            if (closed < open) {
                current += ')';
                solve (n, open, closed + 1, current, result);
                current.pop_back();
                // remove back of current
            }
        }
        

};
