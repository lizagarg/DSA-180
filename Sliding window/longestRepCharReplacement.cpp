class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int l=0, r=0, maxf=0, maxlen=0;
        unordered_map<char, int>mp;

        while(r<n) {
            mp[s[r]]++;
            maxf=max(maxf, mp[s[r]]);

            //if not valid
            while((r-l+1)-maxf >k) {
                mp[s[l]]--;
                l++;
            }
            //becomes valid
            maxlen= max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};

/*
TC: O(N+N) r and l traverse
SC: O(26) for the unordered_map that stores the frequency of characters.

*/