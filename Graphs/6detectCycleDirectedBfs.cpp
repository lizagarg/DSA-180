class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++) {
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        vector<int>ans;
        
        for(int i=0; i<V; i++) {
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(ans.size()==V) return false;
        return true;
    }
};