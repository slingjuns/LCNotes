# 567. Permutation in String

Careful: No
Date: November 7, 2021
Difficulty: Medium
Elegant Code (Template): Sliding Window
Index: 567
Programming Language: C++
Skills: 1. Use hashmap to check permutation
Tags: Sliding Window
Link: https://leetcode.com/problems/permutation-in-string/

```python
from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        c_s1 = Counter(s1)
        c_s2 = Counter()
        win_size = len(s1)
        l = 0
        for i, c in enumerate(s2):
            c_s2[c] += 1
            if i-l+1 > win_size:
                left = s2[l]
                if c_s2[left] == 1:
                    c_s2.pop(left)
                else:
                    c_s2[left] -= 1
                l += 1
            if c_s1 == c_s2:
                return True
        return False
```