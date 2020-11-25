# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        root=head.next
        m,n=head ,head.next
        lastn=ListNode(0)
        while m.next and n.next :
            m.next=n.next
            n.next=m
            lastn.next=n
            lastn=m
            m=m.next
            n=m.next
        if(n):
            m.next=n.next
            n.next=m
            lastn.next=n
        return root