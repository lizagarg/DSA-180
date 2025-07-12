/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mp;
    void Dfs(Node* node, Node* clone) {
        for(Node* n: node->neighbors) {
            if(mp.find(n)==mp.end()) {
                Node* newclone= new Node(n->val);
                mp[n]=newclone;
                clone->neighbors.push_back(newclone);
                Dfs(n,newclone);
            } else {
                clone->neighbors.push_back(mp[n]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* clone= new Node(node->val);
        mp[node]= clone;
        Dfs(node,clone);
        return clone;
    }
};