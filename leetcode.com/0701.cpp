#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      if(root == NULL)
        return new TreeNode(val);
      TreeNode *curr = root;
      while(curr){
        if(curr->val > val){
          if(curr->left)
            curr = curr->left;
          else{
            curr->left = new TreeNode;
            curr = curr->left;
            break;
          }
        }else{
          if(curr->right)
            curr = curr->right;
          else{
            curr->right = new TreeNode;
            curr = curr->right;
            break;
          }
        }
      }
      curr->val = val;
      return root;
    }
};

void solve() {
  Solution s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
