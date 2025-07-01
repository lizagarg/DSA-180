class Solution {
    int solve(int i,int size,vector<int>& nums,vector<int>&dp){
        if(i<0) return 0;
        if (dp[i] != -1)  return dp[i];

        int inc = nums[i]+solve(i-2,size,nums,dp);
        int exl = solve(i-1,size,nums,dp);
        
        return dp[i]=max(inc,exl);
    }
public:
    int rob(vector<int>& nums) {
        int size =nums.size();
        vector<int>dp(size,-1);
        return solve(size-1,size,nums,dp);
    }
};

/*
TC: O(n) 
SC: O(n) for dp array + O(n) for recursion stack
*/