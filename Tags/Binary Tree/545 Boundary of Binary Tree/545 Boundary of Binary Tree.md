# 545. Boundary of Binary Tree

Careful: No
Index: 545
Programming Language: C++
Skills: 1. Add two parameters to the dfs function (isLeft Boundary, isRight Boundary)
2. Each node now knows if it is a left boundary or right boundary
3. Can even know if the node is left or right child or its parent
Tags: Binary Tree
Link: https://leetcode.com/problems/boundary-of-binary-tree/

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isLeaf(self, root):
        if root and not root.left and not root.right:
            return True
        return False
    
    def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
        res = [root.val]
        def helper(root, isLeftB, isRightB):
            if not root:
                return
            if self.isLeaf(root):
                res.append(root.val)
                return
            if isLeftB:
                res.append(root.val)
            helper(root.left, isLeftB, not root.right and isRightB)
            helper(root.right, not root.left and isLeftB, isRightB)
            if isRightB:
                res.append(root.val)
        helper(root.left, True, False)
        helper(root.right, False, True)
        return res
```