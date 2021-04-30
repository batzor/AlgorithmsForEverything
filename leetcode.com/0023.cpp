#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      struct ListNode *ret = new ListNode(0);
      struct ListNode *ans = ret;
      cout << ans->val << endl;
      while(!lists.empty()){
        int min_index = -1;
        for(int i = 0; i < lists.size();i++){
          if(lists[i]){
            if(min_index < 0)
              min_index = i;
            else if(lists[min_index]->val > lists[i]->val)
              min_index = i;
          }
        }
        if(min_index < 0)
          break;
        ret->next = new ListNode(lists[min_index]->val);
        ret = ret->next;
        lists[min_index] = lists[min_index]->next;
        if(!lists[min_index])
          lists.erase(lists.begin() + min_index);
      }
      return ans->next;
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
