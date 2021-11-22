// Date: November 22, 2021
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        zeros = left = maxv = 0
        first_zero = -1
        for i, num in enumerate(nums):
            if num == 0: 
                zeros += 1
                if first_zero == -1: first_zero = i
            if zeros > 1:
                left = first_zero + 1
                first_zero = i
                zeros -= 1
            maxv = max(maxv, i-left+1)
        return maxv - 1
