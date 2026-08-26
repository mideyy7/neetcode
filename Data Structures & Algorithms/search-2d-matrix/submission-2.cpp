class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        ig (rows == 0) return false;
        int cols = matrix[0].size();
        int lo = 0;
        int hi = (rows * cols) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / rows][mid % rows] == target) return true;
            if (matrix[mid / rows][mid % rows] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
