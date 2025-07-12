class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<int>st;
        int n= a.size();
        vector<int>res(n,0);

        for(int i=n-1; i>=0; i--) {
            //pop until you find next greatest
            while(!st.empty() && a[i]>= a[st.top()]) {
                st.pop();
            }
            if(st.empty()) res[i]=0;
            else res[i]= st.top()-i;

            st.push(i);
        }
        return res;
    }
};
/*
TC: O(2*N) because each element is pushed and popped from the stack at most once.
SC: O(N) for the stack and result vector.

brute force approach would take O(N^2) time.
*/