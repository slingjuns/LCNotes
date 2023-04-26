# 1618. Maximum Font to Fit a Sentence in a Screen

Careful: Yes
Index: 1618
Programming Language: C++
Skills: 1. Be careful about whehter or not the returned value is a valid one
2. How to know? Look at the lowerbound or the upperbound of the binary search
Tags: Binary Search, Range Binary Search
Link: https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/

```python
class Solution:
    def maxFont(self, text: str, w: int, h: int, fonts: List[int], fontInfo : 'FontInfo') -> int:
        def isValid(size):
            sum_w = 0
            hei = fontInfo.getHeight(size)
            for c in text:
                wid = fontInfo.getWidth(size, c)
                sum_w += wid
            return sum_w <= w and hei <= h
        lo, hi = 0, len(fonts)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if isValid(fonts[mid]): lo = mid + 1
            else: hi = mid
        return -1 if lo == 0 else fonts[lo-1]
```