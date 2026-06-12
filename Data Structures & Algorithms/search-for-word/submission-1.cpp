class Solution {
    private:
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*
        iterate through the grid and find a match for the first letter..
        solve(row, col, visited, word, index(1)) return bool
        if index = len(word).. return true
        for dr, dc in direction:
            if grid[dr][dc] == word[index] and !visiyed
                 mark as visited
                    result = solve(dr, dc, visited, index + 1)
                    if result return true
        return false
        */
        vector<vector<bool>> visited (board.size(), vector<bool>(board[0].size(), false));
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (board[r][c] == word[0]) {
                    if (solve(r, c, board, visited, word, 1)) return true;
                }
            }
        }
        return false;     
    }

    bool solve (int row, int col,vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index) {
        if (index == word.size()) return true;
        visited[row][col] = true;
        for (auto [dr, dc] : directions) {
            int nr = dr + row;
            int nc = dc + col;
            bool is_valid = nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size();
            if (is_valid && !visited[nr][nc] && board[nr][nc] == word[index] && solve(nr, nc, board, visited, word, index + 1)) return true;
        }
        visited[row][col] = false;
        return false;
    }
};
