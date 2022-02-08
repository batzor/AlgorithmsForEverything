/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<TreeNode *> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int node_num = bfs.size();
            vector<int> cur_level;
            for(int i = 0; i < node_num;i++){
                TreeNode *ptr = bfs.front();
                bfs.pop();
                cur_level.push_back(ptr->val);
                if(ptr->left)
                    bfs.push(ptr->left);
                if(ptr->right)
                    bfs.push(ptr->right);
            }
            ret.push_back(cur_level);
        }
        return ret;
    }
};