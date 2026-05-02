class Solution {
private:
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    max_area = max(max_area, dfs(grid, i , j, visited));
                }
            }
        }
        return max_area;

        
    }

    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || visited[row][col] || grid[row][col] == 0){
            return 0;
        }
        visited[row][col] = true;
        int area = 1;
        for (auto &[d_row, d_col] : directions) {
            area += dfs(grid, row + d_row, col + d_col, visited);
        }
        return area;
    }
};
