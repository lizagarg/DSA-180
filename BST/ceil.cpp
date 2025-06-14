void helper(Node* root, int key, int &ans) {
        if(!root) return;
        
        if(root->data<key) helper(root->right, key, ans);
        else if(root->data >=key) {
            ans= root->data;
            helper(root->left,key,ans);
        }
        return;
    }

int findCeil(Node* root, int input) {
    // Your code here
     int ans=-1;
        helper(root,input,ans);
        return ans;
    
}