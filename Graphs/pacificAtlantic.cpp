class Solution {
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int i, int j, int oi, int oj) {
        if(i<0 || i>=heights.size() || j<0|| j>=heights[0].size()|| vis[i][j]) return;
        if(oi >=0 && oj>=0 && heights[i][j]<heights[oi][oj]) return; //water wont flow

        //mark visited
        vis[i][j]=true;
        dfs(heights,vis,i-1,j,i,j);
        dfs(heights,vis,i+1,j,i,j);
        dfs(heights,vis,i,j-1,i,j);
        dfs(heights,vis,i,j+1,i,j);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int n= heights.size(); //rows
        int m= heights[0].size(); //cols

        vector<vector<bool>> pac(n,vector<bool>(m));
        vector<vector<bool>> atl(n,vector<bool>(m));

        for(int i=0; i<n; i++) {
            dfs(heights,pac,i,0,-1,-1); //first col
            dfs(heights,atl,i,m-1,-1,-1); //last col
        }

        for(int j=0; j<m; j++) {
            dfs(heights,pac,0,j,-1,-1); //first row
            dfs(heights,atl,n-1,j,-1,-1); //last row
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};