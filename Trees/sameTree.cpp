class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p==NULL || q==NULL) return p==q;
       bool ans1=isSameTree(p->left, q->left);
       bool ans2=isSameTree(p->right, q->right);
       return ans1 && ans2 && p->val == q->val;
    }
}; 