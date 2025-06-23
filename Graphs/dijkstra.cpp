// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //step-1 build adj list
        vector<vector<pair<int,int>>>adj(V);
        for(auto edge:edges) {
            int node= edge[0], it= edge[1], weight=edge[2];
            adj[node].push_back({it,weight});
        }
        
        //step-2 dist vector and min heap pq
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        
        //step-3 algo
        while(!pq.empty()) {
            int node= pq.top().second;
            int d= pq.top().first;
            pq.pop();
            
            //check for neighbours
            for(auto it: adj[node]) {
                int adjnode= it.first;
                int adjdis= it.second;
                if(d+adjdis < dist[adjnode]) {
                    //update
                    int newDistance= adjdis+d;
                    dist[adjnode]= newDistance;
                    pq.push({newDistance, adjnode});
                }
            }
        }
        return dist;
    }
};