class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int s=0, e=n-1;
        int ans=INT_MAX;
        while(s<=e) {
            int mid= (s+e)/2;
            if(nums[s]<=nums[mid]) {
                //left part sorted , store and check in right
                ans=min(ans, nums[s]);
                s=mid+1;
            } else {
                ans= min(ans, nums[mid]);
                e=mid-1;
            }
        }
        return ans;
    }
};

/*
TC: O(log n) for the binary search, where n is the size of the input array.
SC: O(1) for the pointers used in the binary search.
*/