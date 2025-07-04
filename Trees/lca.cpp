class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(!root) return nullptr;
       if(root==p || root==q) return root;

       TreeNode* l= lowestCommonAncestor(root->left, p, q);
       TreeNode* r= lowestCommonAncestor(root->right, p, q);

       if(l==NULL) return r;
       else if(r==NULL) return l;
       else return root; 
    }
};