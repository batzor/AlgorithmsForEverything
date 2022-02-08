/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<int> path;
        return dfs(root, path);
    }
    
    int dfs(TreeNode* root, vector<int> &path){
        if(root == NULL)
            return 0;
        path.push_back(root->val);
        int ret;
        if(root->left || root->right){
            ret = dfs(root->left, path) + dfs(root->right, path);
        }else{
            ret = calcPath(path);
        }
        path.pop_back();
        return ret;
    }
    
    int calcPath(vector<int> &path){
        int num = pow(2, path.size() - 1);
        int sum = 0;
        for(auto i: path){
            if(i == 1)
                sum += num;
            num /= 2;
        }
        return sum;
    }
};