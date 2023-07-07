# 774. Minimize Max Distance to Gas Station

Careful: Yes
Difficulty: Hard
Index: 774
Programming Language: C++
Skills: 1. Key idea is that you can modify last element on the vector directly by vector.back()[1] = …
Tags: Binary Search, Greedy
Link: https://leetcode.com/problems/minimize-max-distance-to-gas-station/

```python
def minmaxGasDist(self, st, K):
        left, right = 1e-6, st[-1] - st[0]
        while left + 1e-6 < right:
            mid = (left + right) / 2
            count = 0
            for a, b in zip(st, st[1:]):
                count += math.ceil((b - a) / mid) - 1
            if count > K:
                left = mid
            else:
                right = mid
        return right
```