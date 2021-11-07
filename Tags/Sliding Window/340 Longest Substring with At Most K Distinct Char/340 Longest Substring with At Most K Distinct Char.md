# 340. Longest Substring with At Most K Distinct Characters

Careful: No
Date: November 7, 2021
Difficulty: Medium
Index: 340
Programming Language: C++
Skills: 1. Use hashmap to store the last seen index of a character
Tags: Sliding Window
Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

```python
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        d = {}
        low, ret = 0, 0
        for i, c in enumerate(s):
            d[c] = i
            if len(d) > k:
                low = min(d.values())
                del d[s[low]]
                low += 1
            ret = max(i - low + 1, ret)
        return ret
```