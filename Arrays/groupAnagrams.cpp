class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string &s: strs) {
            string dup= s;
            sort(dup.begin(), dup.end());
            mp[dup].push_back(s);
        }

        vector<vector<string>> res;
        for(auto &i :mp) {
            res.push_back(i.second);
        }
        return res;
    }
};