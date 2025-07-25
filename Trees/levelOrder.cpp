class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root) return ans;
        q.push(root);
        
        while(!q.empty()) {
            int size=q.size();
            vector<int>level;
            for(int i=0; i<size; i++) {
                TreeNode* node= q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};