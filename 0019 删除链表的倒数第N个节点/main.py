# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        length=0
        node=head
        LOfN=[]
        while(node):
            LOfN.append(node)
            node = node.next
        if(n>=len(LOfN)):
            head=head.next
        else:

            LOfN[-n-1].next=LOfN[-n].next
        return head
            
