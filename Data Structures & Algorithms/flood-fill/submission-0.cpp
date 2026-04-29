class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, sr, sc, visited, initial_color, color);
        return image;
    }

    vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>>& image, int i, int j, vector<vector<bool>> &visited, int initial_color, int color) {
        image[i][j] = color;
        visited[i][j] = true;
        for (auto [d_i, d_j] : directions) {
            int n_i = i + d_i, n_j = j + d_j;
            bool isValid = n_i >= 0 && n_i < image.size() && n_j >= 0 && n_j < image[0].size();
            if (isValid && !visited[n_i][n_j] && image[n_i][n_j] == initial_color) {
                dfs(image, n_i, n_j, visited, initial_color, color);
            }
        }
    }
};