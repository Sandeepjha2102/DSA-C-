class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image,
             vector<vector<int>>& ans, int initialCol, int color) {
        ans[row][col] = color;

        int n = image.size();
        int m = image[0].size();

        // move 4 directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == initialCol && ans[nrow][ncol] != color) {
                dfs(nrow, ncol, image, ans, initialCol, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int initialCol = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, image, ans, initialCol, color);
        return ans;
    }
};