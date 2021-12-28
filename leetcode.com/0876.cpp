#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode *cur = head, *mid = head;
            for(int i = 0; cur->next;++i){
                cur = cur->next;
                if(i % 2 == 0)
                    mid = mid->next;
            }
            return mid;
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

