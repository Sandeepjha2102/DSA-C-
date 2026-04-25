class Solution {
public:

    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& matrix){
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(matrix[i][j] != -1) return matrix[i][j];

        int left = solve(obstacleGrid, i, j-1, matrix);
        int right = solve(obstacleGrid, i-1, j, matrix);

        return matrix[i][j] = left + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = obstacleGrid.size();
        int j = obstacleGrid[0].size();
        vector<vector<int>> matrix(i, vector<int>(j, -1));
        
        return solve(obstacleGrid, i-1, j-1, matrix);
    }
};