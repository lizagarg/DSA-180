class Solution {
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>&vis) {
        if(i<0 || j<0|| i>=board.size() || j>= board[0].size()||vis[i][j] || board[i][j]!='O') return;
        //mark visited
        vis[i][j]=1;
        //dfs call for neighbours
            dfs(i+1,j,board,vis);
            dfs(i-1,j,board,vis);
            dfs(i,j+1,board,vis);
            dfs(i,j-1,board,vis);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n= board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        //first and last col
        for(int i=0; i<m; i++) {
            if(board[i][0]=='O') dfs(i,0,board,vis);
            if(board[i][n-1]=='O') dfs(i,n-1,board,vis);
        }
        
        //for first and last row
        for(int j=0; j<n; j++) {
            if(board[0][j]=='O') dfs(0,j,board,vis);
            if(board[m-1][j]=='O') dfs(m-1,j,board,vis);
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]=='O' && !vis[i][j]) {
                    //mark it X
                    board[i][j]='X';
                }
            }
        }
    }
};