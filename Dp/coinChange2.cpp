class Solution {
public:
    int solve(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(target%coins[0]==0) return 1;
            else return 0;
        }
        if(target==0) return 1;

        if(dp[ind][target] != -1) return dp[ind][target];

        int notTake=solve(ind-1,target,coins,dp);
        int take=0;
        if(target>=coins[ind]) take=solve(ind,target-coins[ind],coins,dp);

        return dp[ind][target]=take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       return solve(n-1,amount,coins,dp);
    }
};

//tabulation
class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount+1,0));

        //base case
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int t=0; t<=amount; t++) {
                long long notTake= dp[i-1][t];
                long long take=0;
                if(coins[i]<=t) take= dp[i][t-coins[i]];
                dp[i][t]=(take+notTake>INT_MAX) ? INT_MAX: take+notTake;
            }
        }
        return (int)dp[n - 1][amount];
    }
};
