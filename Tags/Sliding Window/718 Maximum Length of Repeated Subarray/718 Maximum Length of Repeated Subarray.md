# 718. Maximum Length of Repeated Subarray

Careful: No
Date: November 22, 2021
Difficulty: Medium
Index: 718
Programming Language: C++
Tags: Sliding Window
Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/

```python
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        nums1 = "".join([chr(ch) for ch in nums1])
        temp = ""
        res = 0
        for num in nums2:
            temp += chr(num)
            if temp in nums1:
                res = max(res,len(temp))
            else:
                temp = temp[1:]
        return res
```