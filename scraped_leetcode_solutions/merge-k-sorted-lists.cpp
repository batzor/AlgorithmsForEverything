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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *root = NULL;
        ListNode **cur = &root;
        lists.erase(std::remove_if(lists.begin(), lists.end(), 
                       [](ListNode * p) { return p == NULL; }), lists.end());
        while(!lists.empty()){
            auto min_it = lists.begin();
            for(auto it = lists.begin(); it != lists.end();++it){
                if((*min_it)->val > (*it)->val)
                    min_it = it;
            }
            (*cur) = (*min_it);
            (*min_it) = (*min_it)->next;
            if((*min_it) == NULL)
                lists.erase(min_it);
            cur = &((*cur)->next);
            
        }
        return root;
    }
};