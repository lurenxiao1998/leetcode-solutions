# Definition for a binary tree node.
from typing import List
import json


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        cur = root
        r = []

        while cur:
            if (not cur.left):
                r.append(cur.val)
                cur = cur.right
            else:
                tmp = cur.left
                flag = False
                while(tmp.right != None):
                    if(tmp.right == cur):
                        tmp.right = None
                        flag = True
                    else:
                        tmp = tmp.right
                        # flag = False
                if not flag:
                    tmp.right = cur
                    r.append(cur.val)
                    cur = cur.left
                else:
                    cur = cur.right
        return r

def stringToTreeNode(input):
    input = input.strip()
    input = input[1:-1]
    if not input:
        return None

    inputValues = [s.strip() for s in input.split(',')]
    root = TreeNode(int(inputValues[0]))
    nodeQueue = [root]
    front = 0
    index = 1
    while index < len(inputValues):
        node = nodeQueue[front]
        front = front + 1

        item = inputValues[index]
        index = index + 1
        if item != "null":
            leftNumber = int(item)
            node.left = TreeNode(leftNumber)
            nodeQueue.append(node.left)

        if index >= len(inputValues):
            break

        item = inputValues[index]
        index = index + 1
        if item != "null":
            rightNumber = int(item)
            node.right = TreeNode(rightNumber)
            nodeQueue.append(node.right)
    return root

def integerListToString(nums, len_of_list=None):
    if not len_of_list:
        len_of_list = len(nums)
    return json.dumps(nums[:len_of_list])

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
            root = stringToTreeNode(line);
            
            ret = Solution().preorderTraversal(root)

            out = integerListToString(ret);
            print(out)
        except StopIteration:
            break
    
if __name__ == "__main__":
    main()