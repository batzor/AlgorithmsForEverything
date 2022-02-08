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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        getElements(root1, v1);
        getElements(root2, v2);
        
        vector<int> ret;
        int i = 0;
        int j = 0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i] > v2[j]){
                ret.push_back(v2[j]);
                ++j;
            }else{
                ret.push_back(v1[i]);
                ++i;
            }
        }
        for(;i < v1.size();++i)
            ret.push_back(v1[i]);
        for(;j < v2.size();++j)
            ret.push_back(v2[j]);
        return ret;
    }
    void getElements(TreeNode* root, vector<int> &ret){
        if(!root)
            return;
        getElements(root->left, ret);
        ret.push_back(root->val);
        getElements(root->right, ret);        
    }
};