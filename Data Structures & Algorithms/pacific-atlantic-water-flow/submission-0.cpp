class Solution {
   public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& islands, int x, int y) {
        int rows = islands.size();
        int cols = islands[0].size();

        islands[x][y] = true;

        if (x - 1 >= 0 && !islands[x - 1][y] && heights[x - 1][y] >= heights[x][y]) {
            dfs(heights, islands, x - 1, y);
        }
        if (x + 1 < rows && !islands[x + 1][y] && heights[x + 1][y] >= heights[x][y]) {
            dfs(heights, islands, x + 1, y);
        }
        if (y + 1 < cols && !islands[x][y + 1] && heights[x][y + 1] >= heights[x][y]) {
            dfs(heights, islands, x, y + 1);
        }
        if (y - 1 >= 0 && !islands[x][y - 1] && heights[x][y - 1] >= heights[x][y]) {
            dfs(heights, islands, x, y - 1);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacificIslands(heights.size(), vector<bool>(heights[0].size(), false));

        vector<vector<bool>> atlanticIslands(heights.size(),
                                             vector<bool>(heights[0].size(), false));

        for (int i = 0; i < cols; i++) {
            dfs(heights, pacificIslands, 0, i);
            dfs(heights, atlanticIslands, rows - 1, i);
        }
        for (int i = 1; i < rows; i++) {
            dfs(heights, pacificIslands, i, 0);
            dfs(heights, atlanticIslands, rows - 1 - i, cols - 1);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacificIslands[i][j] && atlanticIslands[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};