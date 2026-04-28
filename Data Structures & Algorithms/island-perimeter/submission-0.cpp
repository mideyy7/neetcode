class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        unordered_set<int> visited;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, visited, perimeter);
                    return perimeter;
                }
            }
        }
        return perimeter;
        
        
    }



    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {-1, 0}, {1,0}};
    void dfs(int i, int j, vector<vector<int>>& grid, unordered_set<int> &visited, int &perimeter) {
        visited.insert(i * grid[0].size() + j);

        for (auto &[d_i, d_j] : directions) {
            int n_i = i + d_i;
            int n_j = j + d_j;
            bool isValid = n_i >= 0 && n_i < grid.size() && n_j >= 0 && n_j < grid[0].size() && grid[n_i][n_j] == 1;
            if (!isValid) {
                perimeter ++;
            } else if (visited.find(n_i * grid[0].size() + n_j) == visited.end()) {
                dfs(n_i, n_j,  grid, visited, perimeter);
            }
        }
    }
    
};