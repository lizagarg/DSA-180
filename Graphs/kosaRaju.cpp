class Solution {
  public:
    void toposort(int node, vector<vector<int>> &adj, vector<int>&vis, stack<int>&st) {
        vis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) toposort(it, adj, vis, st);
        }
        //while returning, push to stack
        st.push(node);
        return;
    }  
    
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj) {
        vis[node]=1;
        for(auto it: adj[node]) {
            if(!vis[it]) dfs(it, vis, adj);
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n= adj.size();
        vector<int>visited(n,0);
        stack<int>st;
        
        //step-1 topological sort
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                toposort(i,adj,visited,st);
            }
        }
        
        //step-2 Transpose the graph
        vector<vector<int>> newAdj(n);
        for(int i=0; i<n; i++) {
            //for every node
            for(auto it: adj[i]) {
                newAdj[it].push_back(i);
            }
            //for every node, clear the visited array
            visited[i]=0;
        }
        
        //step-3 Dfs traversal on transpose graph according to stack
        int cnt=0;
        while(!st.empty()) {
            int node= st.top();
            st.pop();
            if(!visited[node]) {
                dfs(node, visited, newAdj);
                cnt++;
            }
        }
        return cnt;
    }
};

/*
3 step algorithm:
1. Do a topological sort of the original graph and store the nodes in a stack.
2. Transpose the graph (reverse the direction of edges).
3. Do a DFS traversal on the transposed graph according to the order of nodes in the stack.
The number of times you start a DFS traversal in step 3 gives the number of strongly connected components (SCCs) in the graph.
This algorithm is known as Kosaraju's algorithm for finding strongly connected components in a directed graph
*/ 