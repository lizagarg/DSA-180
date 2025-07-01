class Solution {
    int helper(int i, vector<int>&temp, vector<int>&dp) {
        int prev= temp[0];
        int prev2=0;

        for(int i=1; i<temp.size(); i++) {
            int take= temp[i];
            if(i>1) take+=prev2; //otherwise prev2 wont exist
            int notTake= prev;
            int curr= max(take, notTake);
            prev2= prev;
            prev=curr;
        }

        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        vector<int>temp1, temp2;
        for(int i=0; i<n; i++) {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        vector<int>dp1(temp1.size(),-1);
        vector<int>dp2(temp2.size(),-1);

        int val1= helper(temp1.size()-1, temp1, dp1);
        int val2= helper(temp2.size()-1, temp2, dp2);

        return max(val1,val2);
    }
};

/*
TC:
O(n) for each helper call
SC:
O(n) for temp1 and temp2
O(1) because space optimization is done in helper function
*/