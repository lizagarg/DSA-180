//application of Dijkstra's algorithm to find the shortest path in a graph
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time: times) {
            int src= time[0], des=time[1], w= time[2];
            adj[src].push_back({des,w});
        }

        //vector
        vector<int>time(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        time[k]=0;
        pq.push({0,k});

        //algo
        while(!pq.empty()) {
            int node= pq.top().second;
            int currtime= pq.top().first;
            pq.pop();

            for(auto it: adj[node]) {
                int adjnode= it.first;
                int timeval= it.second;

                if(currtime+timeval < time[adjnode]) {
                    //update
                    time[adjnode]= currtime+timeval;
                    pq.push({time[adjnode],adjnode});
                }
            }
        }
        int maxi=0;
        for(int i=1; i<n+1; i++) {
            if(time[i]==INT_MAX) return -1;
            maxi= max(maxi,time[i]);
        }
        return maxi;
    }
};