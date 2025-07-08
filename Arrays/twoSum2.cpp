class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int i=0, j=n-1;
        while(i<j) {
            if(numbers[i]+numbers[j]==target) return {i+1,j+1};
            else if(numbers[i]+numbers[j]<target) i++;
            else if(numbers[i]+numbers[j]>target) j--;
        }
        return {};
    }
};

/*
TC: O(n)
SC: O(1) for the two pointers i and j, hence total space complexity is O(1)
This solution is optimal as it uses a two-pointer technique on a sorted array.
*/