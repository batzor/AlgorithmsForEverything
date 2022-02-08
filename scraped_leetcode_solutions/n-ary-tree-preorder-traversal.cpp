/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void recurse(Node *node, vector<int> &v) {
        if(node == nullptr)
            return;
        v.push_back(node->val);
        for(auto child: node->children){
            recurse(child, v);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ret;
        this->recurse(root, ret);
        return ret;
    }
};