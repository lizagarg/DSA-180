class Solution {
    int memoization(int i,vector<int>& nums,vector<vector<int>>& dp,int s,int target){
        if(i<0){
            if(s==target) return 1;
            return 0;
        }
        if(dp[i][s+1000]!=-1) return dp[i][s+1000];
        int add=memoization(i-1,nums,dp,s+nums[i],target);
        int sub=memoization(i-1,nums,dp,s-nums[i],target);
        return dp[i][s+1000]=add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return memoization(n-1,nums,dp,0,target);
    }
};

//method 2
class Solution {
    int f(int i,vector<int>& nums,vector<vector<int>>& dp,int target){
        
        if(i==0) {
            if(target==0 && nums[0]==0) return 2;
            if(target==0) return 1;
            if(target==nums[0]) return 1;
            return 0;
        }

        if(dp[i][target]!=-1) return dp[i][target];
        
        int take=0;
        if (nums[i] <= target) take = f(i-1, nums, dp, target-nums[i]);
        int notTake= f(i-1, nums, dp, target);

        return dp[i][target]= take+notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        if((sum+target)<0 || (sum+target)%2==1) return 0;
        int newTarget= (sum+target)/2;
        vector<vector<int>>dp(n,vector<int>(newTarget+1,-1));
        return f(n-1,nums,dp,newTarget);
    }
};