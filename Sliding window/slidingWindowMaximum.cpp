class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0; i<n; i++) {
            //front- largest element, back- adding more for later
            if(!dq.empty() && dq.front()<=i-k) {
                //not in current window
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()]) {
                //current element is greater than elements on top, pop them all and store this one
                dq.pop_back();
            }

            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

//TC: O(n) + O(n)  
//SC; O(k)+ O(n-k)

/*
The outer for loop runs n times (n = nums.size()).
Each element is added and removed from the deque exactly once.
So total number of deque operations (push and pop) is O(n).
*/
