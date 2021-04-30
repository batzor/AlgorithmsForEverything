# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode, r = 0) -> ListNode:
        ret = ListNode(0)
        temp = ret
        c = 0

        while l1 or l2 or c:            
            val1  = (l1.val if l1 else 0)
            val2  = (l2.val if l2 else 0)

            val = val1 + val2 + c
            c = val // 10
            val = val % 10

            temp.next = ListNode(val)
            temp = temp.next                      

            l1 = (l1.next if l1 else None)
            l2 = (l2.next if l2 else None)

        return ret.next
