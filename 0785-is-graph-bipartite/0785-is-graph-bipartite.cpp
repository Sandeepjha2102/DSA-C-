class Solution {
public:
    bool check(int start, int col, vector<vector<int>>& graph, vector<int> &color){
        color[start] = col;
        
        for(auto it:graph[start]){
            if(color[it] == -1){
                if(check(it, !col, graph, color) == false) return false;
            } 
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> color(V, -1);       

        //for component graphs
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(check(i, 0, graph, color) == false) return false;
            }
        }
        return true;
    }
};