class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /*

        llop : for i -> index to n
                    curr.push(i)
                    solve(i + 1, curr, result)
                    curr.pop()
                    solve(i + 1, curr, result)


        */
        vector<int> current;
        vector<vector<int>> result;
        solve(n, k, 1, current, result);
        return result;
        
    }

    void solve(int n, int k, int index, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        if (index > n) return;
    
            current.push_back(index);
            solve(n, k, index + 1, current, result);
            current.pop_back();
            solve(n, k, index + 1, current, result);
 
    }
};