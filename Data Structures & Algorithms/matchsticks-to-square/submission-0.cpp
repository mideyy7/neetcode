class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        /*
        at every point i can add or subtract
        solve(matchsticks, index, current)
        base condition ->   
              if current < 0:
                return false
            if index == len(sticks) : 
                                if current == 0 return true else return false
        solve(sticks , index + 1, current +sticks[index])
        solve(sticks, index + 1, current - sticks[index])
        */
        return solve(matchsticks, 0, 0);
    }

    bool solve(vector<int>& matchsticks, int index, int current) {
        if (current < 0) return false;
        if (index == matchsticks.size()) {
            if (current == 0) return true;
            return false;
        }
        return solve(matchsticks, index + 1, current + matchsticks[index]) || solve(matchsticks, index + 1, current - matchsticks[index]);
    }
};