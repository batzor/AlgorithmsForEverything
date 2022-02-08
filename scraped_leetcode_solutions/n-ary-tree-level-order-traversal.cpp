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
    inline void goDown(vector<vector<int>> &ret, vector<Node *> &q){
        vector<int> lvl;
        int n = q.size();
        for(int i = 0; i < n;i++){
            lvl.push_back(q[i]->val);
            q.insert(q.end(), q[i]->children.begin(), q[i]->children.end());
        }
        q.erase(q.begin(), q.begin() + n);
        ret.push_back(lvl);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;
        vector<Node *> q;
        q.push_back(root);
        while(!q.empty())
            goDown(ret, q);
        return ret;
        
    }
};