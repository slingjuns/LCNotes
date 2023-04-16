# 1283. Find the Smallest Divisor Given a Threshold

Careful: No
Index: 1283
Programming Language: C++
Tags: Binary Search, Range Binary Search
Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

![jpg.jpeg](jpg.jpeg)

```python
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        import math
        def sum_div(d):
            return sum(math.ceil(v/d) for v in nums)
        lo, hi = 1, max(nums)
        while lo < hi:
            mid = lo + (hi-lo) // 2
            if sum_div(mid) <= threshold: hi = mid
            else: lo = mid + 1
        return lo
```