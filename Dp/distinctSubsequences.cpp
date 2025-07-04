class Solution {
    int f(int i, int j, string &s, string &t, vector<vector<int>>&dp) {
        if(j<0) return 1; //all matched hence s2 goes out
        if(i<0) return 0; // only s1 went out. s2 remaining
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]= f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        else return dp[i][j]= f(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return f(s.size()-1, t.size()-1, s,t,dp);
    }
};