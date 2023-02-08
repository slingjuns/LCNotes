# 1300. Sum of Mutated Array Closest to Target

Careful: No
Index: 1300
Programming Language: C++
Tags: Binary Search, Range Binary Search
Link: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

```python
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        def mutatedSum(k):
            sum = 0
            for v in arr:
                if v > k: sum += k
                else: sum += v
            return sum
        lo, hi = 1, max(arr) + 1
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if mutatedSum(mid) >= target: hi = mid
            else: lo = mid + 1
        if abs(mutatedSum(lo-1)-target) <= abs(mutatedSum(lo)-target):
            return lo-1
        return lo
```