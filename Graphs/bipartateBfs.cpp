class Solution {
    bool bfs(int src, vector<vector<int>>& graph, vector<int>&color) {
        color[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()) {
            int node= q.front();
            q.pop();
            for(auto it: graph[node]) {
                if(color[it]==-1) { //uncolored
                    color[it] = 1 - color[node];
                    q.push(it);
                } else if(color[it]==color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes= graph.size();
        vector<int>color(nodes,-1);
        for(int i=0; i<nodes; i++) {
            if(color[i]==-1) {
                if(bfs(i,graph,color)==false) return false;
            }
        }
        return true;
    }
};