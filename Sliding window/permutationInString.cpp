class Solution {
    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i=0; i<26; i++) {
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        //step 1- store s1 freq
        for(int i=0; i<s1.length(); i++) {
            freq[s1[i]-'a']++;
        }

        int windowSize= s1.length();

        //step2 store s2 in windows
        for(int i=0; i<s2.length(); i++) {
            int windowFreq[26]={0};
            int windIndex=0, idx=i;
            while(windIndex<windowSize && idx<s2.length()) {
                windowFreq[s2[idx]-'a']++;
                windIndex++;
                idx++;
            }
            //step3- check if same freq
            if(isFreqSame(freq, windowFreq)) return true;
        }
        return false;
    }
};


//approach 2
class Solution {
public:
    bool checkInclusion(string t, string s) {
        int m= t.size();
        int l=0, r=0;
        int hash[256]={0};
        int minlen=INT_MAX, cnt=0;
        
        //step1 store t
        for(int i=0; i<m; i++) hash[t[i]]++;

        //step2
        while(r<s.size()) {
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
         
            while(cnt==m) {
                //store current value
                if(r-l+1<minlen) minlen=r-l+1;
                //shrink to find the smallest window
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
                //if cnt becomes less, r++
                //expand again
            }
            r++;
        }
        return minlen==m; //if we found a window of size m, then it is a permutation
    }
};

//algo in words
/*1. Store the frequency of characters in string t.
2. Use two pointers (l and r) to create a sliding window in string s.
3. Expand the right pointer (r) to include characters in the window and decrease their frequency in the hash table.
4. Update count variable when a positive frequency is found.
4. If the count of characters in the window matches the size of t, check if the window size is equal to m (the size of t).
5. If it is, return true, indicating that a permutation of t exists in s.
6. If the window size is greater than m, shrink the window from the left by increasing l and updating the hash table.
7. Repeat steps 3-6 until the end of string s is reached.
*/