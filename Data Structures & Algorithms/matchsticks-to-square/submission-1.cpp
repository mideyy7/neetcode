class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        vector<int> sides (4, 0);
        for (int stick : matchsticks) {
            total += stick;
        }
        int length = total / 4;
        if (length * 4 != total) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return solve(matchsticks, 0, sides, length);   
    }

    bool solve(vector<int>& matchsticks, int index, vector<int>& sides, int length) {
        if (index == matchsticks.size()) return true;
        for (int i = 0; i < 4; ++i) {
            if (matchsticks[index] + sides[i] <= length) {
                sides[i] += matchsticks[index];
                if (solve(matchsticks, index + 1, sides, length)) return true;
                sides[i] -= matchsticks[index];
            }
        }
        return false;
    }
};