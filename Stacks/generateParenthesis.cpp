class Solution {
    void f(int open, int close, int n, string &res, vector<string>&ans) {
        //base case 
        if(res.size()==2*n) {
            ans.push_back(res);
            return;
        }

        if(open<n) {
            res.push_back('(');
            f(open+1, close, n, res, ans);
            res.pop_back();
        }
        if(close<open) {
            res.push_back(')');
            f(open, close+1, n, res, ans);
            res.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res="";
        f(0,0,n,res,ans);
        return ans;
    }
};

/*
TC:
*/