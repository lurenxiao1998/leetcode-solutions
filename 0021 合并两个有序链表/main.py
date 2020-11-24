# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        rn = ListNode(0)
        root=rn
        l=l1
        r=l2
        while(l and r):

            if( min (l.val,r.val)==l.val):
                rn.next = ListNode(l.val)
                l=l.next
                rn = rn.next
            else:
                rn.next = ListNode(r.val)
                r=r.next
                rn=rn.next
        if(r):
            # rn.val=r.val
            rn.next=r
        else:
                # rn.val=l.val
            rn.next=l
        return root.next
