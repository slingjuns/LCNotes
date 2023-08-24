# 236. Lowest Common Ancestor of a Binary Tree

Careful: Yes
Difficulty: Medium
Index: 236
Programming Language: C++
Skills: 1. Both two children exist in the Binary Tree.
Tags: Binary Tree, LCA
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
        if root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right: # the lowest common ancestor
            return root
        return left or right
```