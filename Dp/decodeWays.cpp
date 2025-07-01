class Solution {
    int helper(int i, string &s, int n, vector<int>&dp) {
        if(i==n) return 1; // reached till end, one valid split

        if(s[i]=='0') return 0; // cant split

        if(dp[i]!=-1) return dp[i];

        int only_first= helper(i+1,s, n, dp);
        int both=0;
        if(i+1<n){
            if(s[i]=='1' || s[i]=='2' && s[i+1]<='6') both= helper(i+2, s,n, dp);
        }

        return dp[i]= only_first+both;
    }
public:
    int numDecodings(string s) {
        int n= s.size();
        vector<int>dp(n,-1);
        return helper(0, s, n, dp);
    }
};

/*
Tc: O(n)
Sc: O(n) for dp array + O(n) for recursion stack
This is a top-down approach using memoization.

If tabulation is used then
Tc: O(n)
Sc: O(n) for dp array
*/