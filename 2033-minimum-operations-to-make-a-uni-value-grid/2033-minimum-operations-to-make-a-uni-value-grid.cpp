class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flatten;
        int rem = grid[0][0] % x;
        //flattening the grid
        for(int i = 0; i <  grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] % x != rem) return -1;
                flatten.push_back(grid[i][j]);
            }
        }
        sort(begin(flatten), end(flatten));
        for(int i = 0; i < flatten.size(); i++){
            cout << flatten[i] << " ";
        }
        int median = flatten.size() / 2; 
        cout << endl << flatten[median];

        int operations = 0;
        for(int i = 0; i < flatten.size(); i++){
            operations += abs(flatten[i] - flatten[median]) / x;
        }
        return operations;
    }
};