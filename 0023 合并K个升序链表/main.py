class Solution:
    
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists)==0:
            return None
        orderedL = lists[0]
        
        def merge( l,r): 
            
            mNode=ListNode(0)
            root=mNode
            while l and r:
                if l.val < r.val:
                    mNode.next=ListNode(l.val)
                    l=l.next
                    mNode=mNode.next
                else:
                    mNode.next=ListNode(r.val)
                    r=r.next
                    mNode=mNode.next
            if l:
                mNode.next = l
            else:
                mNode.next = r
            return root.next
        
        while len(lists) > 1:
            mergedL=[]
            if len(lists)%2==1:
                mergedL.append(lists.pop())
                print(lists)
            for idx in range(len(lists)//2):
                
                mergedL.append(merge( lists[2 * idx] ,lists[2 * idx+1]))
            lists=mergedL
        return lists[0]