# 475. Heaters

Careful: No
Index: 475
Programming Language: C++
Skills: 1. Key Idea is find the nearest heater (similar to find_nearest_element in a sorted array)
Tags: Binary Search, Range Binary Search
Link: https://leetcode.com/problems/heaters/

```python
def find_nearest_heater(house_n, heaters):
        lo, hi = 0, len(heaters)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if heaters[mid] >= house_n:
                hi = mid
            else:
                lo = mid + 1

        if lo == len(heaters):
            lo = len(heaters)-1
        elif lo != 0:
            left_heater = lo - 1
            left_dist, right_dist = abs(heaters[lo-1]-house_n), abs(heaters[lo]-house_n)
            if left_dist < right_dist:
                lo = left_heater
        return abs(heaters[lo]-house_n)

class Solution:
    
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        res = 0
        heaters = sorted(heaters)
        for h in houses:
            step = find_nearest_heater(h, heaters)
            res = max(res, step)
        return res
```