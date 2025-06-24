class Solution {
    int dfs(int i, int j, vector<vector<int>>&vis, vector<vector<int>>& grid, int m, int n) {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1 && !vis[i][j]) {
            //mark visited
            vis[i][j]=1;
            return 1+ dfs(i+1,j,vis,grid,m,n)+dfs(i-1,j,vis,grid,m,n)+dfs(i,j+1,vis,grid,m,n)+dfs(i,j-1,vis,grid,m,n);
        } 
        else
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size(); //rows
        int m= grid[0].size(); //columns
        int maxi=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    int cnt= dfs(i,j,vis,grid,m,n);
                    maxi= max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};