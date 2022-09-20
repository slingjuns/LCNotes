# 889. Construct Binary Tree from Preorder and Postorder Traversal

Careful: Yes
Date: September 20, 2022
Difficulty: Medium
Index: 889
Programming Language: C++
Skills: 1. Pre-Order and Post-Order can be combined to use
2. When we meet a node value pre[i] equals to the current post[j], it means we have completed building the subtree of pre[i]. So we should not continue to add child nodes to that subtree. Instead, we should pop that subtree and continues to the path where we can add child nodes.
Tags: Binary Tree, Construct Tree
Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

```python
preIndex, posIndex = 0, 0
    def constructFromPrePost(self, pre, post):
        root = TreeNode(pre[self.preIndex])
        self.preIndex += 1
        if (root.val != post[self.posIndex]):
            root.left = self.constructFromPrePost(pre, post)
        if (root.val != post[self.posIndex]):
            root.right = self.constructFromPrePost(pre, post)
        self.posIndex += 1
        return root
```