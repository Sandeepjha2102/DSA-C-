class Solution {
public:
    int n, m;

    vector<vector<int>> directions {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool find(int i, int j, int index, string& word, vector<vector<char>>& board){
        //base conditions
        if(index == word.length()){
            return true;
        }
        if(i<0 || j<0 || i>= n || j>= m || board[i][j] == '$') return false;

        if(board[i][j] != word[index]) return false;


        char temp = board[i][j];
        board[i][j] = '$';

        for(auto& dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(find(new_i, new_j, index+1, word, board)){
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0] && find(i,j,0,word, board)){
                    return true;
                }
            }
        }
        return false;
    }
};