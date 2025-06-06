class Solution {
public:
    int helper(TreeNode* root, int &maxi) {
        if(!root) return 0;
        int lh= helper(root->left, maxi);
        int rh= helper(root->right, maxi);
        maxi=max(maxi,lh+rh);
        return 1+max(lh,rh);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        helper(root,maxi);
        return maxi;
    }
};