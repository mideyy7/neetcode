class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        int result = 0;
        for (int j = 1; j <= n / 2; ++j) {
            int val = max((j * (n - j)), j * integerBreak(n - j));
            result = max(result, val);
        }
        return result;
    }
};