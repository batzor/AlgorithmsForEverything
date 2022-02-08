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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        stack<ListNode*> ptrs;
        ListNode *ptr = head;
        while(ptr != NULL){
            ptrs.push(ptr);
            ptr = ptr->next;
        }
        ListNode *ret = ptrs.top();
        ptrs.pop();
        ptr = ret;
        while(!ptrs.empty()){
            ptr->next = ptrs.top();
            ptr = ptr->next;
            ptrs.pop();
        }
        ptr->next = NULL;
        return ret;
    }
};