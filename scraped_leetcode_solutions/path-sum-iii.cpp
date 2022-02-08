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
    int pathSum(TreeNode* root, int sum, bool is_self = false) {
        if(root == NULL)
            return 0;
        
        int self_start = 0;
        int left_start = 0;
        int right_start = 0;
        
        self_start = pathSum(root->left, sum - root->val, true)
                        + pathSum(root->right, sum - root->val, true);
        if(sum - root->val == 0)
            self_start += 1;
        
        if(!is_self){
            left_start = pathSum(root->left, sum);
            right_start = pathSum(root->right, sum);
        }
        
        return self_start + left_start + right_start;
    }
};