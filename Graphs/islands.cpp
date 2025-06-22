class Solution {
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n) {
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()) {
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            //traverse neighbours
            int delrow[]= {-1, 0, 1, 0};
            int delcol[]= {0, 1, 0, -1};

            for(int k=0; k<4; k++) {
                int nrow= row+delrow[k];
                int ncol= col+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});                                
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    bfs(i,j,grid,vis,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};