class Solution {
public:
        int ROWS, COLS;
        bool pacific, atlantic;
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
                ROWS = heights.size();
                COLS = heights[0].size();
                vector<vector<int>> result;

                for (int r = 0; r < ROWS; ++r) {
                    for (int c = 0; c < COLS; ++c) {
                        pacific = false;
                        atlantic = false;
                        dfs(heights, r , c, INT_MAX);
                        if (pacific && atlantic) {
                            result.push_back({r,c});
                        }
                    }

                }
                return result;
            }

            void dfs(vector<vector<int>>& heights, int r, int c , int prev_value) {
                if (r < 0 || c < 0) {
                    pacific = true;
                    return;
                }
                if (r >= ROWS || c >= COLS) {
                    atlantic = true;
                    return;
                }
                if (heights[r][c] > prev_value) {
                    return;
                }

                int temp = heights[r][c];
                heights[r][c] = INT_MAX;
                for (auto& dir: directions) {
                    dfs(heights, r + dir[0], c + dir[1], temp);
                    if (pacific && atlantic) {
                        break;
                    }
                }
                heights[r][c] = temp;
            }
};
