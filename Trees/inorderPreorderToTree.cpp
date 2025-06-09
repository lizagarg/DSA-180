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
    TreeNode* build(vector<int>& preorder,int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int,int>&mp) {
        if(prestart> preend || instart>inend) return nullptr;

        TreeNode* root= new TreeNode(preorder[prestart]);
        //find this in inorder
        int inroot= mp[root->val];
        //find how many numbers on left
        int numleft= inroot- instart;

        root->left= build(preorder, prestart+1, prestart+numleft, inorder, instart, inroot-1, mp);
        root->right= build(preorder, prestart+numleft+1, preend, inorder, inroot+1, inend, mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>mp;
        // step-1 hash the values of inorder
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]]=i;
        }

        TreeNode* root= build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};