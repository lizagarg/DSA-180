class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1= a.size();
        int n2= b.size();
        if(n1 > n2) return findMedianSortedArrays(b,a);
        int elementsOnLeft= (n1+n2+1)/2;
        int n=n1+n2;
        int low=0;
        int high= n1;
        while(low<=high) {
            int mid1= (low+high)/2;
            int mid2= elementsOnLeft- mid1;
            int l1= INT_MIN, l2=INT_MIN;
            int r1= INT_MAX, r2= INT_MAX;

            if(mid1<n1) r1= a[mid1];
            if(mid2<n2) r2= b[mid2];

            if(mid1-1>=0) l1= a[mid1-1];
            if(mid2-1>=0) l2= b[mid2-1];

            if(l1<=r2 && l2<=r1) {
                //valid
                if(n%2==1) return max(l1,l2);
                else return (double)(max(l1,l2)+min(r1,r2))/2.0;
            } else if(l1 > r2) high=mid1-1;
            else low= mid1+1;
        }
        return 0;
    }
};

/*
optimal approach
TC:O(log(min(n1,n2))) where n1 and n2 are the sizes of the two arrays.
SC:O(1) for the pointers and variables used in the binary search.
*/

//brute force
/*
using 2 pointers , create a new array in a sorted manner and then find median
TC: O(n1+n2) for merging the two arrays, where n1 and n2 are the sizes of the two arrays.
SC: O(n1+n2) for the merged array.

better
using 2 pointers, find the median without merging (use counter to find the index values required to find median)
eliminates the need for a new array
TC: O(n1+n2) for traversing the two arrays, where n1 and n2 are the sizes of the two arrays.
SC: O(1) for the pointers and variables used in the two-pointer approach.
*/


//hard ques