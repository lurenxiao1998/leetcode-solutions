# Definition for singly-linked list.
import json
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        hhead=ListNode(0,head)
        nextH=hhead.next
        root=head
        surplus=False
        while( nextH):
            crtH=hhead.next
            nextH=crtH.next
            for i in range(k-1):
                if(nextH==None):
                    surplus==True
                    break
                nnextH=nextH.next
                nextH.next = crtH
                crtH = nextH
                hhead.next.next = nnextH
                nextH=nnextH
            tmp = hhead.next
            hhead.next = crtH
            hhead = tmp

        if(surplus):
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

def stringToIntegerList(input):
    return json.loads(input)

def stringToListNode(input):
    # Generate list from the input
    numbers = stringToIntegerList(input)

    # Now convert that list into linked list
    dummyRoot = ListNode(0)
    ptr = dummyRoot
    for number in numbers:
        ptr.next = ListNode(number)
        ptr = ptr.next

    ptr = dummyRoot.next
    return ptr

def listNodeToString(node):
    if not node:
        return "[]"

    result = ""
    while node:
        result += str(node.val) + ", "
        node = node.next
    return "[" + result[:-2] + "]"

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            head = stringToListNode(line);
            line = next(lines)
            k = int(line);
            
            ret = Solution().reverseKGroup(head, k)

            out = listNodeToString(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()