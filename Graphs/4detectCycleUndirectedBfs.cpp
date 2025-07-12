class Solution {
    bool detect(int src, vector<vector<int>>& adj, vector<int>&vis) {
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()) {
            int node= q.front().first;
            int parent= q.front().second;
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it]=1;
                    q.push({it,node});
                } else if(parent!=it) return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(V,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
};