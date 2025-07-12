class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>&ls, vector<int>&vis) {
        vis[node]=1;
        ls.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]) dfs(it,adj,ls,vis);
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int start=0;
        int n= adj.size();
        vector<int>ls;
        vector<int>vis(n);
        dfs(0,adj,ls,vis);
        return ls;
    }
};