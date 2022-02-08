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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        bool swap = false;
        ListNode tmp;
        tmp.next = head;
        ListNode *cur = head;
        ListNode *prev = cur;
        ListNode *pprev = &tmp;
        while(cur->next){
            cur = cur->next;
            swap = !swap;
            if(swap){
                pprev->next = cur;
                prev->next = cur->next;
                cur->next = prev;
                cur = prev;
                pprev = prev;
            }else{
                prev = cur;
            }
        }
        return tmp.next;
    }
};