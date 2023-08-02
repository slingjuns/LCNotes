# 1740. Find Distance in a Binary Tree

Careful: No
Difficulty: Medium
Index: 1740
Programming Language: C++
Skills: Use Two Pass on LCA
1. For two nodes on the tree, first find the LCA of the nodes
2. Count the distance given the LCA
Tags: Binary Tree, LCA
Link: https://leetcode.com/problems/find-distance-in-a-binary-tree/

```python
class Solution:
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        def LCA(root, p, q):
            if not root:
                return None
            if root.val == p or root.val == q:
                return root
            left, right = LCA(root.left, p, q), LCA(root.right, p, q)
            if left and right:
                return root
            return left or right

        def dist(root, target):
            if not root:
                return float('inf')
            if root.val == target:
                return 0
            return min(dist(root.left, target), dist(root.right, target)) + 1
        lca = LCA(root, p, q)
        return dist(lca, p) + dist(lca, q)

```