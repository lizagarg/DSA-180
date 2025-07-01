class Solution {
    bool check(int i, int j, vector<vector<int>>&dp, string &s) {
        //base case
        if(i>=j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=check(i+1, j-1, dp, s);
        return dp[i][j]= 0;
    }
public:
    string longestPalindrome(string s) {
        int n= s.size();
        int sp=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maxlen=INT_MIN;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(check(i,j,dp,s)) {
                    if(j-i+1>maxlen) {
                        maxlen= j-i+1;
                        sp=i;
                    }
                }
            }
        }

        return s.substr(sp,maxlen);
    }
};

/*
TC-> O(n^2)
SC-> O(n^2) for dp
     and O(n) for recursion stack
*/