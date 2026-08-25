class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int check = mid * mid;
            if (check == x) return mid;
            if (check > x) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
        
    }
};