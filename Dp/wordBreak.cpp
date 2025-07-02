class Solution {
    bool f(string& s, unordered_set<string>& dict, int i, vector<int>& dp) {
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];

        for(int l = 1; l <= s.size(); l++) {
            string temp = s.substr(i, l);
            if(dict.find(temp) != dict.end()) {
                if(f(s, dict, i + l, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);
        return f(s, dict, 0, dp);
    }
};
