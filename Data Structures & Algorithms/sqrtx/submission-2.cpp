class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int left = 1;
        int right = x / 2;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long check = mid * mid;
            if (check == x) return static_cast<int>(mid);
            if (check > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return static_cast<int>(right);
        
    }
};