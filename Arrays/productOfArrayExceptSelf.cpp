class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        vector<int>ans(n,1);

        for(int i=1; i<n; i++) prefix[i]=prefix[i-1]*nums[i-1];
        for(int i=n-2; i>=0; i--) suffix[i]= suffix[i+1]*nums[i+1];
        for(int i=0; i<n; i++) ans[i]= prefix[i]*suffix[i];

        return ans;
    }
};

/*
TC: O(N) for prefix and suffix arrays, and O(N) for final result array
SC: O(N) for prefix, suffix, and ans arrays
*/

//approach 2
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans(n,1);
        //store prefixes
        for(int i=1; i<n; i++) {
           ans[i]=ans[i-1]*nums[i-1];
        }
        
        //multiply with suffix
        int suffix=1;
        for(int i=n-2; i>=0; i--) {
            suffix=suffix*nums[i+1];
            ans[i]=ans[i]*suffix;        
        }
 
        return ans;
    }
};