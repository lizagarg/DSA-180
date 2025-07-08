class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto &num: nums) mp[num]++;

        priority_queue<pair<int,int>> maxheap;

        for(auto &it: mp) maxheap.push({it.second, it.first});

        vector<int>res;
        for(int i=0; i<k; i++) {
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return res;
    }
};

/*
TC: O(N) map+
O(NlogN) maxheap -> N elements loop amd logN for each push +
O(KlogN) for K elements loop and logN for each pop

SC: O(N) for map and maxheap + O(K) for result vector
hence, total space complexity is O(N)
*/