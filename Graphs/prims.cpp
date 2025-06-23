class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int sum=0;
        vector<int>vis(V,0);
        //weight,node
        pq.push({0,0});
        
        while(!pq.empty()) {
            int wt= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            //got the node. if already visited->DONOT PROCESS
            if(vis[node]) continue;
            //else store/add value+mark visited
            sum+=wt;
            vis[node]=1;
            
            //check adj
            for(auto it: adj[node]) {
                int adjnode= it[0];
                int adjwt= it[1];
                if(!vis[adjnode]) pq.push({adjwt,adjnode});
            }
            
        }
        return sum;
    }
};