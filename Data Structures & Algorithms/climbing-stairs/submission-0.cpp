class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        return climbStairs(n - 1) + climbStairs(n - 2);
        /*
        base case is if n == 0: return 1
        if n < 0: return 0 as this is not a valid path
        solve(n - 1) + solve(n - 2)
        */
        
    }
};
