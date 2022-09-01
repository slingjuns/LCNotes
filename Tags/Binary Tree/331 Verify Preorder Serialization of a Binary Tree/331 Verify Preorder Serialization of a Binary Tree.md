# 331. Verify Preorder Serialization of a Binary Tree

Careful: No
Date: September 1, 2022
Difficulty: Medium
Index: 331
Programming Language: C++
Skills: 1. Verify the tree using the Pre-Order Traversal
2. Don’t worry about how the traversing index moves since the index will move like the Pre-Order Traversal
Tags: Binary Tree, Construct Tree
Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

```python
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        self.nums = list(preorder.split(","))
        self.idx = 0
        def helper():
            if self.idx > len(self.nums) - 1: return False
            if self.nums[self.idx] == '#': 
                self.idx += 1
                return True
            self.idx += 1
            return helper() and helper()
        res = helper()
        return res and self.idx == len(self.nums)
```