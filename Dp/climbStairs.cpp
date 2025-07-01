class Solution {
    int climb(vector<int>&dp,int i) {
        if(i==0 || i==1) return 1;

        if(dp[i]!=-1) return dp[i];

        int l= climb(dp, i-1);
        int r= climb(dp, i-2);

        return dp[i]=l+r;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climb(dp,n); 
    }
};

/*
TC: O(n)
SC: O(n) for dp array + O(n) for recursion stack
This is a top-down approach using memoization.

if tabulation is used then
TC: O(n)
SC: O(n) for dp array
This is a bottom-up approach using tabulation.

if space optimization is used then
TC: O(n)
SC: O(1) because only 2 variables are used to store previous results.
*/