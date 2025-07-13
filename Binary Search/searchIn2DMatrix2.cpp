class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        //start from top right col
        int m= mat.size();
        int n=mat[0].size();
        int r= 0, c=n-1;
        while(c>=0 && r<m) {
            if(mat[r][c]==target) return true;
            else if(target<mat[r][c]) {
                //discard col
                c--;
            } else r++;
        }
        return false;
    }
};