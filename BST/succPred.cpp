/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    Node* findPre(Node* root, int key) {
        Node* pre= NULL;
        while(root) {
            if(key<= root->data) root=root->left;
            else {
                pre= root;
                root=root->right;
            }
        }
        return pre;
    }
    
    Node* findSucc(Node* root, int key) {
        Node* succ= NULL;
        while(root) {
            if(key>= root->data) root=root->right;
            else {
                succ= root;
                root=root->left;
            }
        }
        return succ;
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>res;
        Node* val1= findPre(root,key);
        Node* val2= findSucc(root,key);
        res.push_back(val1);
        res.push_back(val2);
        return res;
    }
};