class Solution {
  public:
    int n;
    vector<vector<int>>dp;
    int f(int i, int j, vector<int> &arr) {
        if(i==j) return 0; //single matrix
        
        if(dp[i][j]!=-1) return dp[i][j];
        //partitions
        int mini= 1e9;
        for(int k=i; k<j; k++) {
            int steps= arr[i-1]*arr[k]*arr[j] +f(i,k,arr)+f(k+1, j, arr);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        n= arr.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return f(1, n-1, arr);
    }
};

/*
Tc: O(n^2) x O(n) for the loop inside the function
Sc: O(n^2) for dp array + O(n) for recursion stack
*/