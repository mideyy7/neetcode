class Solution {
public:
    int countServers(vector<vector<int>>& grid)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int count = 0;
        for (int row = 0; row < ROWS; ++row) {
            int row_sum = accumulate(grid[row].begin(), grid[row].end(), 0);
            if (row_sum > 1) {
                count += row_sum;
                for (int col = 0; col < COLS; ++col) {
                    if (grid[row][col] == 1){
                        grid[row][col] = -1;
                    } 
                }
            }
        }

        for (int col = 0; col < COLS; ++col) {
            int col_sum = 0;
            int take = 0;
            for (int row = 0; row < ROWS; ++row) {
                if (grid[row][col] < 0) {
                    grid[row][col] = 1;
                } else if (grid[row][col] > 0) {
                    take += 1;
                }
                col_sum += grid[row][col];
            }
            if (col_sum > 1) {
                count += take;
            }
        }
        return count;

    }
};
       