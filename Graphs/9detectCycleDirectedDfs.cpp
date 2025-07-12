class Solution {
    bool dfs(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&dfsvis) {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[it]==1) //both arrays 1= cycle
            return true;
        }
        //backtrack
        dfsvis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int>vis(V,0);
        vector<int>dfsvis(V,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i,adj,vis,dfsvis)) return true;
            }
        }
        return false;
    }
};