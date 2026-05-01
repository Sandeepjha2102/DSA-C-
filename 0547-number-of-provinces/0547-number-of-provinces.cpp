class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected,  vector<int> &ls){
        ls[node] = 1;
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[node][j] == 1 && !ls[j]){
                dfs(j, isConnected, ls);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
       
        int V = isConnected.size();
        vector<int> ls(V, 0);

        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!ls[i]){
                dfs(i, isConnected, ls);
                cnt++;
            }
        }
        return cnt;
    }
};