class Solution {
    void helper(Node* root, int key, int &ans) {
        if(!root) return;
        
        if(root->data>key) helper(root->left, key, ans);
        else if(root->data <=key) {
            ans= root->data;
            helper(root->right,key,ans);
        }
        return;
    }

  public:
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        helper(root,x,ans);
        return ans;
    }
};