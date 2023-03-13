# 1008. Construct Binary Search Tree from Preorder Traversal

Careful: Yes
Difficulty: Medium
Index: 1008
Programming Language: C++
Skills: 1. Construct BST by passing lower and higher limit or each node
2. If the val is within the range, the node is valid
Tags: Binary Tree, Construct Tree
Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

```python
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        self.idx = 0
        def helper(low_limit, high_limit):
            if self.idx >= len(preorder):
                return None
            root = None
            if preorder[self.idx] > low_limit and preorder[self.idx] < high_limit:
                root = TreeNode(val=preorder[self.idx])
                self.idx += 1
                root.left = helper(low_limit, root.val)
                root.right = helper(root.val, high_limit)
            return root
        return helper(float("-inf"), float("inf"))
```