class Solution {
    bool f(int i, int target, vector<int>&nums, vector<vector<int>>&dp) {
        //base case
        if(target==0) return true;
        if(i==0) return nums[0]==target;

        if(dp[i][target]!=-1) return dp[i][target];

        //not-take
        bool notTake= f(i-1, target, nums, dp);
        bool take= false;
        if(nums[i]<=target) {
            take= f(i-1, target-nums[i], nums, dp);
        }

        return dp[i][target]= take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int i=0; i<n; i++) {
            sum+= nums[i];
        }

        if(sum%2==1) return false;
        int target= sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return f(n-1, target, nums, dp);
    }
};