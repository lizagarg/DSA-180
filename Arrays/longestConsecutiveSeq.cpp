class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        if(n==0) return 0;
        int count=1, maxi=1;
        for(int i=1; i<n; i++) {
            if(nums[i]==nums[i-1]+1) {
                count++;
                maxi=max(maxi,count);
            } else if(nums[i]==nums[i-1]) continue;
            else count=1;
        }
        return maxi;
    }
};

/*
TC: O(NlogN) for sorting + O(N) for linear traversal
SC: O(1) for count and maxi, hence total space complexity is O(1)
This solution is not optimal, as it uses sorting which is O(NlogN).

An optimal solution would use a hash set to achieve O(N) time complexity.
*/

// Optimal solution using hash set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) { // Check if it's the start of a sequence
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

/*
TC: O(n) for putting elements in the set 
+ O(2N) for checking each element in the set
SC: O(n) for the hash set 
*/