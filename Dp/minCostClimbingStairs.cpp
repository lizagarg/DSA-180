class Solution {
    int helper(int i, vector<int>& cost, vector<int>& dp) {
        if(i==0) return cost[0];
        if(i==1) return cost[1];
        if(dp[i]!=-1) return dp[i];

        //move
        int one= cost[i]+helper(i-1, cost, dp);
        int two= cost[i]+helper(i-2, cost, dp);

        return dp[i]=min(one,two);

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int>dp(n+1,-1);
        int index=0;
        return min(helper(n - 1, cost, dp), helper(n - 2, cost, dp));
    }
};

// redundant