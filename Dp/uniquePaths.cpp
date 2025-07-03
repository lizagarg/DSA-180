class Solution {
    int f(int i, int j, vector<vector<int>>&dp) {
        // base case
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        //move
        int left= f(i, j-1, dp);
        int top= f(i-1, j, dp);

        return dp[i][j]= left+top;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return f(m-1, n-1, dp);
    }
};

//tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        //base case
        dp[0][0]=1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
               if (i == 0 && j == 0) continue; // Skip the starting point
               int up = 0, left = 0;
               if (i > 0) up = dp[i-1][j];
               if (j > 0) left = dp[i][j-1];
               dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
};