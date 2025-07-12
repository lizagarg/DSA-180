class Solution {
    void dfs(int node, vector<int>&vis, stack<int>&st, vector<vector<int>>&adj) {
        vis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) dfs(it, vis, st, adj);
        }
        //while returning, push to stack
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        stack<int>st;
        vector<int>vis(V);
        for(int i=0; i<V; i++) {
            if(!vis[i]) dfs(i, vis, st, adj);
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};