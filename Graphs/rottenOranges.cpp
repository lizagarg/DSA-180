class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();

        queue<pair<pair<int,int>,int>>q; //((row,col),time)
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int fresh=0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {//push to queue and mark
                    q.push({{i,j},0});
                    visited[i][j]=1;
                } else if(grid[i][j]==1) fresh++;
            }
        }

        int maxTime=0;
        int rotted=0;
        vector<int>drow ={-1,0,1,0};
        vector<int>dcol ={0,1,0,-1};

        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            int time= q.front().second;
            q.pop();

            maxTime= max(maxTime,time);

            for(int i=0; i<4; i++) {
                int newrow= row+drow[i];
                int newcol= col+dcol[i];

                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && grid[newrow][newcol]==1 && !visited[newrow][newcol]) {
                    //push into queue
                    //mark visited
                    //rotten count increases
                    q.push({{newrow,newcol},time+1});
                    visited[newrow][newcol]=1;
                    rotted++;
                }
            }
        }

        if(rotted!=fresh) return -1;
        else return maxTime;
        
    }
};