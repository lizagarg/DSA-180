//brute force 
class Solution {
public:
    void helper(TreeNode* root,vector<int>&ans){
        if(!root) return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        helper(root,ans);
        int start=0,end=ans.size()-1;
        while(start<end){
            if(ans[start]+ans[end]==k)return true;
            else if(ans[start]+ans[end]<k)start++;
            else end--;
        }
        return false;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*>st;
    bool reverse=true;
    //reverse= true --before 
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse= isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp= st.top();
        st.pop();
        if(reverse==false) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }

    void pushAll(TreeNode* root) {
        while(root) {
            st.push(root);
            if(reverse==true)
            root=root->right;
            else root=root->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       if(root==NULL) return false;
       BSTIterator l(root,false);
       BSTIterator r(root,true);
       int i= l.next();
       int j= r.next();
       while(i<j) {
        if(i+j==k) return true;
        else if(i+j <k) i=l.next();
        else j=r.next();
       }
       return false;
    }
};