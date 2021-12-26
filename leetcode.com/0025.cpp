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
    ListNode* reverse(ListNode* first, ListNode* last) {
      ListNode* prev = NULL;

      while ( first != last )
      {
	auto tmp = first->next;
	first->next = prev;
	prev = first;
	first = tmp;
      }

      return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode *c = head;
      for(int i = 0;i < k;++i){
	if(c)
	  c = c->next;
	else
	  return head;
      }

      auto new_head = reverse(head, c);
      head->next = reverseKGroup(c, k);
      return new_head;
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
