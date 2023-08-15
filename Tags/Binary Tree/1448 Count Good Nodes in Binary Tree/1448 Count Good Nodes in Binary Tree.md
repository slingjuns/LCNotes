# 1448. Count Good Nodes in Binary Tree

Careful: No
Index: 1448
Programming Language: C++
Skills: 1. We can pass information from the parent node to the children in the Pre-Order Traversal
Tags: Binary Tree
Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

```python
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.res = 0
        def helper(root, cur_max):
            if not root: return
            if root.val >= cur_max:
                cur_max = root.val
                self.res += 1
            helper(root.left, cur_max)
            helper(root.right, cur_max)
        helper(root, root.val)
        return self.res

```