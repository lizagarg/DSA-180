class Solution {
    bool check(int i, int j, vector<vector<int>>&dp, string &s) {
        //base case
        if(i>=j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=check(i+1, j-1, dp, s);
        else return dp[i][j]= 0;
    }
public:
    int countSubstrings(string s) {
        int n= s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(check(i,j,dp,s)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

//bottom up 
class Solution {
public:
//bottom up approach
    int countSubstrings(string s) {
        int n= s.size();
         vector<vector<bool>> t(n, vector<bool>(n, false));
        int cnt=0;

        for(int L=1; L<=n; L++) {
            //for every length
            for(int i=0; i+L-1<n; i++) {
                int j= i+L-1;
                if(i==j) {
                    //one length
                    t[i][j]=true;
                } else if(i+1==j) {
                    //two length
                    t[i][j]= (s[i]==s[j]);
                } else {
                    //generic
                    t[i][j]= (s[i]==s[j] && t[i+1][j-1]);
                }
                if(t[i][j]) cnt++;
            }
        }
        return cnt;
    }
};

// blueprint
