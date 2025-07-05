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

//tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));
        
        
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1; 
        }

        for (int j = 1; j <= n; j++) {
            dp[0][j] = 0; 
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return static_cast<int>(dp[m][n]);
    }
};