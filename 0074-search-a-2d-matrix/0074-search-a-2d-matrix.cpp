class Solution {
public:

    int bs(vector<int>& matrix, int target){
        int size = matrix.size();
        int start = 0;
        int end = size-1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(matrix[mid] == target){
                return true;
            }
            else if(target > matrix[mid]) {
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            if(matrix[i][0] <= target && target <= matrix[i][n-1]){
                    return bs(matrix[i], target);
            }
        }
        return false;
    }
};