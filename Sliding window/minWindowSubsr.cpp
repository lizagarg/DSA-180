class Solution {
public:
    string minWindow(string s, string t) {
        int m= t.size();
        int l=0, r=0, start=-1;
        int hash[256]={0};
        int minlen=INT_MAX, cnt=0;
        
        //step1 store t
        for(int i=0; i<m; i++) {
            hash[t[i]]++;
        }

        while(r<s.size()) {
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
         
            while(cnt==m) {
                if(r-l+1<minlen) {
                    minlen=r-l+1;
                    start=l;
                }
                //shrink
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
                //if cnt becomes less, r++
            }
            r++;
        }
        return start==-1?"":s.substr(start, minlen);
    }
};
