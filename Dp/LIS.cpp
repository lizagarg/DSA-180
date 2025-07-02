class Solution {
    int f(int i, int prev, vector<int>&nums, int n, vector<vector<int>>&dp) {
        //base case
        if(i==n) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int len1 = 0+f(i+1, prev, nums, n, dp);
        int len2=0;
        if(prev==-1 || nums[i]>nums[prev])
        len2= 1+ f(i+1, i, nums, n, dp);

        return dp[i][prev+1]= max(len1, len2);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0, -1, nums, n, dp);
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2) for dp array + O(n) for recursion stack
// This is a top-down approach using memoization.