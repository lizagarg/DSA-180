class Solution {
    /*
    calculate left smallest and right smallest
    and then for each bar, calculate the ans
    */
public:
    int largestRectangleArea(vector<int>& ht) {
        int n= ht.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        stack<int>st;
        //left
        for(int i=0; i<n; i++) {
            while(!st.empty() && ht[i]<=ht[st.top()]) {
                st.pop();
            }

            if(st.empty()) left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }

        // Clear the stack before next use
        while (!st.empty()) st.pop();

        //right
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && ht[i]<=ht[st.top()]) {
                st.pop();
            }

            if(st.empty()) right[i]=n;
            else right[i]=st.top();
            st.push(i);
        }

        //final
        int ans=0;
        for(int i=0; i<n; i++) {
            int area= ht[i]*(right[i]-left[i]-1);
            ans=max(area,ans);
        }

        return ans;

    }
};

//TC: O(N) for calculating left and right boundaries, and O(N) for calculating the area, leading to an overall time complexity of O(N).
//SC: O(N) for the stacks used to find left and right boundaries.