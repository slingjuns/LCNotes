# 314. Binary Tree Vertical Order Traversal

Careful: No
Index: 314
Programming Language: C++
Skills: Put Tree Nodes on a number axis (representing locations )using BFS
Tags: BFS, Binary Tree
Link: https://leetcode.com/problems/binary-tree-vertical-order-traversal/

```python
def verticalOrder(self, root):
    cols = collections.defaultdict(list)
    queue = [(root, 0)]
    for node, i in queue:
        if node:
            cols[i].append(node.val)
            queue += (node.left, i - 1), (node.right, i + 1)
    return [cols[i] for i in sorted(cols)]
```