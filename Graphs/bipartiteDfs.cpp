class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>&color, int col) {
        color[node]=col;
        for(auto it: graph[node]) {
            if(color[it]==-1) {// uncolored 
                int newColor= !col;
                if(!dfs(it, graph, color, newColor)) return false;
            } else if(color[it]==col) return false;//same color
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes= graph.size();
        vector<int>color(nodes,-1);
        for(int i=0; i<nodes; i++) {
            if(color[i]==-1) {
                if(dfs(i,graph,color,0)==false) return false;
            }
        }
        return true;
    }
};