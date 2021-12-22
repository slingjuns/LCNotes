# 209. Minimum Size Subarray Sum

Careful: No
Date: December 22, 2021
Difficulty: Medium
Index: 209
Programming Language: C++
Tags: Sliding Window
Link: https://leetcode.com/problems/minimum-size-subarray-sum/

```python
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = curSum = 0
        minv = float('inf')
        for i, num in enumerate(nums):
            curSum += num
            while curSum >= target:
                minv = min(minv, i-left+1)
                curSum -= nums[left]
                left += 1
            # print(nums[left:i+1], curSum, minv)
        if minv == float('inf'): minv = 0
        return minv
```