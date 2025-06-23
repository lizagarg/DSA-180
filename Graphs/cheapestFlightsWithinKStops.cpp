class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        //create adj list
        for(auto flight: flights) {
            int src= flight[0], dest= flight[1], w=flight[2];
            adj[src].push_back({dest, w});
        }

        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()) {
            int stop= q.front().first;
            int node= q.front().second.first;
            int cost= q.front().second.second;
            q.pop();
            if(stop>k) continue;
            //check neighbours
            for(auto it: adj[node]) {
                int adjnode= it.first;
                int weight= it.second;
                if(cost+weight<dist[adjnode] && stop<=k) {
                    //update
                    dist[adjnode]=cost+weight;
                    q.push({stop+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};