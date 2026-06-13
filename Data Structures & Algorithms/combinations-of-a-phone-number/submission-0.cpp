class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        vector<string> result;
        string current;
        solve(mp, digits, 0, current, result);
        return result;        
    }

    void solve(map<char, vector<char>>& mp, string& digits, int index, string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < mp[digits[index]].size(); ++i) {
            current.push_back(mp[digits[index]][i]);
            solve(mp, digits, index + 1, current, result);
            current.pop_back();
        }
    }
};
