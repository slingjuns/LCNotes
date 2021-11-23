# 978. Longest Turbulent Subarray

Careful: No
Date: November 23, 2021
Difficulty: Medium
Index: 978
Programming Language: C++
Tags: Sliding Window
Link: https://leetcode.com/problems/longest-turbulent-subarray/

```python
class Solution(object):
    def maxTurbulenceSize(self, A):
        N = len(A)
        ans = 1
        anchor = 0

        for i in xrange(1, N):
            c = cmp(A[i-1], A[i])
            if c == 0:
                anchor = i
            elif i == N-1 or c * cmp(A[i], A[i+1]) != -1:
                ans = max(ans, i - anchor + 1)
                anchor = i
        return ans
```