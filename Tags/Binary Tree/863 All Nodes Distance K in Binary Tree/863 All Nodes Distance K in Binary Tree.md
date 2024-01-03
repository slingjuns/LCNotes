# 863. All Nodes Distance K in Binary Tree

Careful: No
Index: 863
Programming Language: C++
Skills: 1. Construct a Graph using the binary tree
2. Apply BFS to find all k-level nodes
Tags: BFS, Binary Tree, Graph
Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

```python
class Solution:
    def distanceK(self, root, target, K):
        conn = collections.defaultdict(list)
        def connect(parent, child):
            # both parent and child are not empty
            if parent and child:
                # building an undirected graph representation, assign the
                # child value for the parent as the key and vice versa
                conn[parent.val].append(child.val)
                conn[child.val].append(parent.val)
            # in-order traversal
            if child.left: connect(child, child.left)
            if child.right: connect(child, child.right)
        # the initial parent node of the root is None
        connect(None, root)
        # start the breadth-first search from the target, hence the starting level is 0
        queue = collections.deque()
        queue.append(target.val)
        visited = set()
        visited.add(target.val)

        for i in range(K):
            level_size = len(queue)

            while level_size != 0:
                item = queue[0]
                for child in conn[item]:
                    
                    if child not in visited:
                        queue.append(child)
                        visited.add(child)

                queue.popleft()
                level_size -= 1
        return list(queue)
```