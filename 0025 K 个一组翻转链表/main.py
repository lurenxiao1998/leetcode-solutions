# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if(head==None):
            return head
        hhead=ListNode(0,head)
        nextH=hhead.next
        root=hhead
        surplus=False
        while( nextH):
            crtH=hhead.next
            nextH=crtH.next
            for i in range(k-1):
                if(nextH==None):
                    surplus=True
                    break
                nnextH=nextH.next
                nextH.next = crtH
                crtH = nextH
                hhead.next.next = nnextH
                nextH=nnextH
            oldhhead = hhead
            tmp = hhead.next
            hhead.next = crtH
            hhead = tmp

        if(surplus):
            hhead = oldhhead
            crtH=hhead.next
            nextH=crtH.next
            for i in range(k-1):
                if(nextH==None):
                    break
                nnextH=nextH.next
                nextH.next = crtH
                crtH = nextH
                hhead.next.next = nnextH
                nextH=nnextH
            tmp = hhead.next
            hhead.next = crtH
            hhead = tmp
        return root.next