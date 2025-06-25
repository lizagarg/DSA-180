class Solution {
    bool dfs(int i, int j, unordered_map<int,vector<int>>&adj, vector<int>&vis) {
        vis[i]=1;
        if(i==j) return true;
        for(auto it: adj[i]) {
            if(!vis[it]) {
                if(dfs(it,j,adj,vis))return true;;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();        
        unordered_map<int,vector<int>>adj;
        for(auto edge: edges) {
            //if these 2 nodes already connected, redundant edge
            int u= edge[0], v=edge[1];
            vector<int>vis(n+1,0);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(u,v,adj,vis)) 
            return {u,v};

            //else add in adj
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};



//DSU APPROACH
class DSU {
    public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=1; i<=n; i++) {
            parent[i]=i; //everyone is their own parent
            rank[i]=0;
        }
    }

    int find(int x) { //find parent of any node
        if(x==parent[x]) return x;
        else return parent[x]=find(parent[x]); 
    }

    void Union(int x, int y) {
        //merge these 2 nodes
        int x_parent= find(x);
        int y_parent= find(y);
        
        if(rank[x_parent]>rank[y_parent]) parent[y_parent]= x_parent;
        else if(rank[y_parent]>rank[x_parent]) parent[x_parent]= y_parent;
        else {
            parent[y_parent]= x_parent; //x parent is y's parent's parent
            rank[x_parent]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();        
        DSU dsu(n);
        for(auto edge: edges) {
            int u= edge[0];
            int v= edge[1];

            if(dsu.find(u)==dsu.find(v)) //same group
                return edge;
            else dsu.Union(u,v);
        }
        return {};
    }
};