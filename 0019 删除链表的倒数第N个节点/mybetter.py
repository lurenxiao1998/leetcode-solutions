# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if(not head.next):
            return None
        nn=0
        head = ListNode(0,head)
        mm , m =head, head
        while(m):
            m=m.next
            if(nn>n):
                mm = mm.next
            nn+=1
        mm.next=mm.next.next
        return head.next