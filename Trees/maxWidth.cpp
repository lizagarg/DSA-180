class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        while(!q.empty()) {
            int size=q.size();
            int minindex=q.front().second;
            long long first, last;
            for(int i=0; i<size; i++) {
                long long curr_index=q.front().second-minindex;
                TreeNode* node= q.front().first;
                q.pop();
                if(i==0) first= curr_index; //first it
                if(i==size-1) last=curr_index; //last it

                if(node->left) q.push({node->left, curr_index*2+1});
                if(node->right) q.push({node->right, curr_index*2+2});
            }

            ans=max(ans, static_cast<int>(last-first+1));
        }
        return ans;
    }
};