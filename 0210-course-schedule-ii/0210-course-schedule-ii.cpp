class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, stack<int> &st){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto &it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis, st)) return true;
            }
            else if(pathVis[it]){
                return true; // cycle detected
            }
        }

        pathVis[node] = 0;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        stack<int> st;

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis, st)){
                    return {}; // cycle → no valid order
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};