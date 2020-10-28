# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        # node = root
        if(not root):
            return []

        nodes = [root]
        result=[]
        while nodes != []:
            node = nodes.pop()
            if(node.right != None):
                nodes.append(node.right)
            if(node.left !=None):
                nodes.append(node.left)
            result.append(node.val)
        return result