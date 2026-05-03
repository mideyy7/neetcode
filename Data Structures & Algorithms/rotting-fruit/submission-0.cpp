class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int fresh_count = 0;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 2) {
                    q.emplace(r,c);
                    visited[r][c] = true;
                } else if (grid[r][c] == 1) {
                    fresh_count += 1;
                }
            }
        }

        int minutes = 0;
        while(!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                auto &[row, col] = q.front();
                q.pop();
            for (auto &[d_row, d_col] : directions) {
                int n_row = row + d_row;
                int n_col = col + d_col;
                bool out_of_bounds = n_row < 0 || n_row >= ROWS || n_col < 0 || n_col >= COLS;
                if (!out_of_bounds && !visited[n_row][n_col] && grid[n_row][n_col] == 1) {
                    visited[n_row][n_col] = true;
                    q.emplace(n_row, n_col);
                    fresh_count -= 1;
                }
            }
            }
            minutes += 1;
        }
        if (fresh_count != 0) {
        return -1;
    }
    if (minutes > 0) {
        minutes -= 1;
    }
    return minutes;
    }
    
};
