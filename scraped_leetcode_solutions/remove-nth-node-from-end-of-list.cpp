/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* nth = head;
        for(int i = 0; i < n;++i){
            cur = cur->next;
        }
        if(!cur)
            return head->next;
        
        while(cur->next){
            cur = cur->next;
            nth = nth->next;
        }
        nth->next = nth->next->next;
        return head;
    }
};