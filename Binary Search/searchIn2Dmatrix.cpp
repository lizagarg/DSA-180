class Solution {
    bool searchInRow(vector<vector<int>>& mat, int target, int row) {
        int n=mat[0].size();
        int start=0;
        int end=n-1;
        while(start<=end) {
            int mid= start+(end-start)/2;
            if(target==mat[row][mid]) return true;
            else if(target>mat[row][mid]) start=mid+1;
            else end=mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        //BS on total rows
        int m=mat.size();
        int n=mat[0].size();
        int startRow=0, endRow=m-1;
        while(startRow<=endRow) {
            int mid= startRow+(endRow-startRow)/2;
            if(target>=mat[mid][0] && target<=mat[mid][n-1]) {
                //found
               return searchInRow(mat, target, mid);
            } else if(target>mat[mid][n-1]) startRow=mid+1;
            else endRow= mid-1;
        }
        return false;
    }
};