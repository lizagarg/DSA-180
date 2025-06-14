class Solution {
    // inverse inorder traversal
    // to get kth largest element
    void helper(Node* root, int k, int &cnt, int &ans) {
        if(!root) return;
        helper(root->right,k,cnt,ans);
        cnt++;
        if(cnt==k) {
            ans= root->data;
            return;
        }
        helper(root->left,k,cnt,ans);
        return;
    }
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        int cnt=0;
        int ans=0;
        helper(root, k, cnt, ans);  
        return ans;
    }
};