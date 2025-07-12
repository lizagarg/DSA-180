class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c: s) {
            if(c=='(' ||c=='[' ||c=='{') st.push(c);
            else {
                if (st.empty()) return false; 
                else if (c == ')' && st.top() == '(') st.pop();
                else if (c == ']' && st.top() == '[') st.pop();
                else if (c == '}' && st.top() == '{') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

// TC: O(N) where N is the length of the string s, as we traverse each character once.
// SC: O(N) in the worst case, where all characters are opening brackets and stored in the stack.
// The overall space complexity is O(N) due to the stack used for storing opening brackets.
// This solution is optimal as it uses a single pass through the string and a stack to keep track of unmatched opening brackets, ensuring that we can validate the parentheses in linear time.