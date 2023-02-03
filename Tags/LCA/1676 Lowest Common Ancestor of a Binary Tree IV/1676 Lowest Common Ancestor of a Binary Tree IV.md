# 1676. Lowest Common Ancestor of a Binary Tree IV

Careful: No
Date: February 3, 2023
Difficulty: Medium
Index: 1676
Programming Language: C++
Tags: Binary Tree, LCA
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/

```cpp
class Solution(object):
    def dfs(self, root, nodes):
        if not root:
            return None
        if root in nodes:
            return root
        left = self.dfs(root.left, nodes)
        right = self.dfs(root.right, nodes)
        if left and right: # the lowest common ancestor
            return root
        return left or right
    
    def lowestCommonAncestor(self, root, nodes):
        
        """
        :type root: TreeNode
        :type nodes: List[TreeNode]
        """
        nodes = set(nodes)
        return self.dfs(root, nodes)
```