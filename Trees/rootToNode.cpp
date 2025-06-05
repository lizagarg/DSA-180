bool helper(TreeNode* root, vector<int>&ans, int B) {
      //base cases
      if(!root) return false;
      ans.push_back(root->val);
      if(root->val==B) return true;
      
      bool val1= helper(root->left, ans, B);
      bool val2= helper(root->right, ans, B);
      
      if(val1||val2) return true;
      
      //or else pop and return false;
      ans.pop_back();
      return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
        vector<int>ans;
        if(A==NULL) return ans;
        helper(A, ans, B);
        return ans;
}