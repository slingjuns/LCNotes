# 1644. Lowest Common Ancestor of a Binary Tree II

Careful: Yes
Date: February 3, 2023
Difficulty: Medium
Elegant Code (Template): DFS, LCA
Index: 1644
Programming Language: C++
Skills: 1. Node may not exist in the tree 2. feed the initial count through Preorder, update the count through Postorder and return 3. Don’t stop when root == p or q, continue searching to update the count
Tags: Binary Tree, LCA
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/

```cpp
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        def dfs(root, p, q, count):
            if not root:
                return None, count
            found = False
            if root == p or root == q:
                count = count-1
                found = True
            left, lc = dfs(root.left, p, q, count)
            right, rc = dfs(root.right, p, q, lc)
            if left and right or found: # the lowest common ancestor
                return root, rc
            return left or right, rc
        
        lca, count = dfs(root, p, q, 2)
        return lca if count == 0 else None
```