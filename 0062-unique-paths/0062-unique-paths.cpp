class Solution {
public:

     int solve(int i, int j, vector<vector<int>>& matrix){
        if(i==0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(matrix[i][j] != -1) return matrix[i][j];

        int left = solve(i,j-1, matrix);
        int right = solve(i-1,j, matrix);

        return matrix[i][j] = left+right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n,-1));  
        return solve(m-1, n-1, matrix);
    }
};