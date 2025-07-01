class Solution {
    int helper(int i, int target, vector<int>& a, vector<vector<int>>&dp) {
        //base case
        if(i==0) {
            if(target% a[i]==0) return target/a[i];
            else return 1e9;
        }

        if(dp[i][target]!=-1) return dp[i][target];

        int notTake= 0+helper(i-1, target, a, dp);
        int take= INT_MAX;
        if(a[i]<=target) take= 1+ helper(i, target-a[i], a, dp);

        return dp[i][target]= min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= helper(n-1, amount, coins, dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};

//tabulation
class Solution {
    int helper(int i, int target, vector<int>& a, vector<vector<int>>&dp) {
        for(int t=0; t<=target; t++) {
            if(t%a[0]==0) dp[0][t]= t/a[0];
            else dp[0][t]=INT_MAX;
        }

        for(int i=1; i<a.size(); i++) {
            for(int t=0; t<=target; t++) {
                int notTake = 0+ dp[i-1][t];
                int take= 1e9;
                if(a[i]<=t) take= 1+ dp[i][t-a[i]];
                dp[i][t]= min(take, notTake);
            }
        }

        return dp[a.size()-1][target];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= helper(n-1, amount, coins, dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};

/*
memo-
TC- O(NxT)
SC- O(NxT) for dp array + O(N) for recursion stack
This is a top-down approach using memoization.

Tabulation
TC- O(NxT)
SC- O(NxT) 
*/