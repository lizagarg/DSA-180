class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        //kahns algo
        vector<int>ans;
        vector<vector<int>>adj(n);
        //create adj list
        for(auto pre: prerequisites) {
            int node= pre[1], neighbour=pre[0];
            adj[node].push_back(neighbour);
        }

        vector<int>indegree(n,0);
        //calculate indegree for each node
        for(int i=0; i<n; i++) {
            for(auto it: adj[i]) indegree[it]++;
        }
        
        
        queue<int>q;
        for(int i=0; i<n; i++) {
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()) {
            int node= q.front();
            q.pop();
            ans.push_back(node);
            //reduce degree of neighbours
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size()==n) return ans;
        else return {};

    }
};