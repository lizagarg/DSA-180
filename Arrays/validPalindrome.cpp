class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;
        for(char c: s) {
            if(isalnum(c)) cleaned+=tolower(c);
        }

        int left= 0;
        int right= cleaned.size()-1;

        while(left<right) {
            if(cleaned[left]!=cleaned[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};

/*
TC: O(N) for cleaning the string and O(N) for checking palindrome
SC: O(N) for the cleaned string
*/

//optimal solution