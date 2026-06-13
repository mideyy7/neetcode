class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string current;
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", 
                            "mno", "pqrs", "tuv", "wxyz"};
                        

        if (digits.empty()) return result;
        solve(0, current, digits, result, mp);
        return result;
    }

    void solve (int index, string& current, string& digits, vector<string>& result, vector<string>& mp) {
        if (current.size() == digits.size()) {
            result.push_back(current);
            return;
        }
        string chars = mp[digits[index] - '0'];
        for (char c: chars) {
            current.push_back(c);
            solve(index + 1, current, digits, result, mp);
            current.pop_back();
        }
    }
};
