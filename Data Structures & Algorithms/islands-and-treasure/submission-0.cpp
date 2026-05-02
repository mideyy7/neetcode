class Solution {
private:
    vector<pair<int, int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        deque<pair<int, int>> q;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 0) {
                    q.emplace_back(r, c);
                    visited[r][c] = true;
                }
            }
        }
        int distance = 0;
        while (!q.empty()) {
            for (int i = 0; i < q.size(); ++i) {
                auto [row, col] = q.front();
                q.pop_front();
                grid[row][col] = distance;
                for (auto &[d_row, d_col] : directions) {
                    int n_col = d_col + col;
                    int n_row = d_row + row;
                    bool out_of_bounds = n_row < 0 || n_row >= ROWS || n_col < 0 || n_col >= COLS;
                    if (!out_of_bounds && !visited[n_row][n_col] && grid[n_row][n_col] != -1) {
                        q.emplace_back(n_row, n_col);
                        visited[n_row][n_col] = true;
                    }
                }

            }
            distance += 1;


        }
        
    }
};
