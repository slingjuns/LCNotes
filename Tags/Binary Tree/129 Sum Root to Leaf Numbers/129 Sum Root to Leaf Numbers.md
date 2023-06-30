# 129. Sum Root to Leaf Numbers

Careful: No
Index: 129
Programming Language: C++
Skills: 1. Pre-Order Traversal
2. Don’t need to know the height of each node (Pre-Order can solve this)
Tags: Binary Tree
Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

```python
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        def helper(root, cur_sum):
            if not root: return
            path_sum = cur_sum*10 + root.val
            if not root.left and not root.right:
                self.res += path_sum
                return
            helper(root.left, path_sum)
            helper(root.right, path_sum)
        helper(root, 0)
        return self.res
```