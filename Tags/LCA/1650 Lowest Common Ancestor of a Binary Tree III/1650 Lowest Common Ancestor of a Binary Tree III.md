# 1650. Lowest Common Ancestor of a Binary Tree III

Careful: No
Difficulty: Medium
Index: 1650
Programming Language: C++
Skills: 1. Treat the tree as a linked list
2. Use the LCA of two linked lists
Tags: Binary Tree, LCA
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

```python
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        a, b = p, q
        while a != b:
            a = a.parent if a.parent else q
            b = b.parent if b.parent else p
        return a

```