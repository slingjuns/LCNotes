# 1182. Shortest Distance to Target Color

Careful: Yes
Index: 1182
Programming Language: C++
Skills: 1. Similar to (Find closest number to a given value in a list)
2. Important: find lower bound of the value (≥ v) and compare to the upper bound of smaller than value (< v)
3. Look carefully how to deal with index out of bound
: dist_prev = i-nums[prev_loc] if prev_loc ≥ 0 else INT.MAX
: dist_cur  = nums[loc]-i if loc < len(nums) else INT.MAX
: min_dist = min(dist_prev, dist_cur)
Tags: Binary Search
Link: https://leetcode.com/problems/shortest-distance-to-target-color/

```python
from bisect import bisect_left
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        # Preprocessing the colors
        color_index = {}
        for i, c in enumerate(colors):
            if c in color_index: color_index[c].append(i)
            else: color_index[c] = [i]
        res = []
        for i, c in queries:
            if c not in color_index: 
                res.append(-1)
                continue
            index_list = color_index[c]
            dist_prev_i, dist_after_i = float("inf"), float("inf")
            loc = bisect_left(index_list, i)
            prev_loc = loc - 1
            dist_prev_i = index_list[prev_loc]-i if prev_loc >= 0 else float("inf")
            dist_after_i = i-index_list[loc] if loc < len(index_list) else float("inf")
            minv = min(dist_prev_i, dist_after_i)
            res.append(minv)
        return res
```