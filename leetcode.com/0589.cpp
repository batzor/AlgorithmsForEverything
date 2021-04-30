#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    Solution s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
