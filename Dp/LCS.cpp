class Solution {
    int f(int i1, int i2, string &text1, string &text2, vector<vector<int>>&dp) {
        //base case
        if(i1<0 || i2<0) return 0; //end of string

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        //match
        if(text1[i1] == text2[i2]) return dp[i1][i2] = 1+ f(i1-1, i2-1, text1, text2, dp);
        else return dp[i1][i2]= max(f(i1, i2-1, text1, text2, dp), f(i1-1, i2, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));

        return f(n-1, m-1, text1, text2, dp);
    }
};

//tabulation
//index shifting
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); 
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0; 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]); 
                }
            }
        }
        return dp[n][m]; 
    }
};