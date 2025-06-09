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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        //hash
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]]=i;
        }
        return build(inorder, 0, inorder.size()-1, postorder,0, postorder.size()-1, mp);
    }

    TreeNode* build(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, map<int,int>&mp) {
        if(instart> inend || poststart>postend) return NULL;
        // fix root and find in inorder
        TreeNode* root= new TreeNode(postorder[postend]);
        int inroot= mp[root->val];
        int numleft= inroot-instart;
        
        root->left= build(inorder, instart, inroot-1, postorder,poststart,poststart+numleft-1, mp);
        root->right= build(inorder, inroot+1, inend, postorder,poststart+numleft, postend-1, mp);

        return root;
    }
};