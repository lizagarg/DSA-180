class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            int target= -nums[i];
            int j=i+1;
            int k=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(j<k) {
                if(nums[j]+nums[k]==target){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(nums[k]==nums[k+1] && j<k) k--;
                }
                else if(nums[j]+nums[k]<target) j++;
                else if(nums[j]+nums[k]>target)k--;
            }
        }
        return ans;
    }
};

// TC: O(N^2) for the two nested loops, where N is the size of the input array.
// SC: O(1) for the pointers and O(M) for the result vector, where M is the number of triplets found.
// The overall space complexity is O(M) due to the result vector, as we are not using any additional data structures that grow with the input size.
// This solution is optimal as it uses sorting and two pointers to find the triplets in O(N^2) time complexity, which is the best we can achieve for this problem.
// The sorting step takes O(N log N) time, but the two-pointer technique ensures that we only traverse the array a limited number of times, leading to an overall time complexity of O(N^2).

//brute
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplets;
        vector<vector<int>>ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());  // ensure same order before inserting
                        triplets.insert(temp);
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};

//TC: O(N^3) for the three nested loops, where N is the size of the input array.
//SC: O(M) for the result vector, where M is the number of unique trip

// better
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplets;
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            int target = -nums[i];
            unordered_set<int> seen;

            for (int j = i + 1; j < n; ++j) {
                int x = target - nums[j];
                if (seen.count(x)) {
                    vector<int> temp = {nums[i], nums[j], x};
                    sort(temp.begin(), temp.end());  // ensure uniqueness
                    triplets.insert(temp);
                    ans.push_back(temp);
                }
                seen.insert(nums[j]);
            }
        }

        return ans;
    }
};

