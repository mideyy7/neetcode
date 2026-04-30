class Solution {
private:
    vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    dfs(grid, row, col, visited);
                    result += 1;
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited)
    {
        visited[row][col] = true;
        for (auto [d_row, d_col] : directions) {
            int n_row = row + d_row;
            int n_col = col + d_col;
            bool is_valid = n_row >= 0 && n_row < grid.size() && n_col >= 0 && n_col < grid[0].size();
            if (is_valid && !visited[n_row][n_col] && grid[n_row][n_col] == '1') {
                dfs(grid, n_row, n_col, visited);
            }
        }

    }
};
