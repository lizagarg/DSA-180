class Solution {
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3 ) {
        if(i==m && j==n && k==N) return true;
        if(k>=N) return false; //only one string used

        if(t[i][j][k]!=-1) return t[i][j][k];

        bool result=false;
        if(s1[i]==s3[k]) result=solve(i+1, j, k+1, s1, s2, s3);
        if(result==true) return t[i][j][k]= true;
        if(s2[j]==s3[k]) result=solve(i, j+1, k+1, s1, s2, s3);

        return t[i][j][k]= result;
    }
public:
    int m, n, N;
    int t[101][101][201];
    bool isInterleave(string s1, string s2, string s3) {
        m= s1.size();
        n= s2.size();
        N= s3.size();
        memset(t,-1, sizeof(t));
        return solve(0,0,0, s1,s2,s3);
    }
};

//TC: O(m*n*N)
//SC: O(m*n*N) for dp array + O(m+n+N) for recursion stack

class Solution {
    bool solve(int i, int j, string &s1, string &s2, string &s3 ) {
        //replaced k by i+j
        if(i==m && j==n && i+j==N) return true;
        if(i+j>=N) return false; //only one string used

        if(t[i][j]!=-1) return t[i][j];

        bool result=false;
        if(s1[i]==s3[i+j]) result=solve(i+1, j, s1, s2, s3);
        if(result==true) return t[i][j]= true;
        if(s2[j]==s3[i+j]) result=solve(i, j+1, s1, s2, s3);

        return t[i][j]= result;
    }
public:
    int m, n, N;
    int t[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        m= s1.size();
        n= s2.size();
        N= s3.size();
        memset(t,-1, sizeof(t));
        return solve(0,0, s1,s2,s3);
    }
};

//TC: O(m*n)
//SC: O(m*n) for dp array + O(m+n) for recursion stack