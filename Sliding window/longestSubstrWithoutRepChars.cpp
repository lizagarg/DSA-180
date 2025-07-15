class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        int l=0, r=0;
        int len=0;
        int maxi=0;
        unordered_map<char,int> mp;

        while(r<n) {
            if(mp.find(s[r])!=mp.end()) {
                //already present in map
                l=max(l,mp[s[r]]+1);
            }
            len=r-l+1;
            maxi=max(maxi,len);
            mp[s[r]]=r;
            r++;
        }
        return maxi;
    }
};

/*
TC: O(N) where N is the size of the input string, as we traverse the string once.
SC: O(N) for the unordered_map that stores the last occurrence of each character.
*/