# 875. Koko Eating Bananas

Careful: Yes
Index: 875
Programming Language: C++
Skills: 1. Be careful about the isPossible Function
Tags: Binary Search, Range Binary Search
Link: https://leetcode.com/problems/koko-eating-bananas/

```python
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def possible(e):
            sum_h = 0
            for ba in piles:
                if ba % e == 0: sum_h += ba // e
                else: sum_h += ba // e + 1
            return sum_h <= h
            
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        l, r = 1, max(piles)+1
        while l < r:
            mid = (l + r) // 2
            if possible(mid): r = mid
            else: l = mid + 1
        return l
```