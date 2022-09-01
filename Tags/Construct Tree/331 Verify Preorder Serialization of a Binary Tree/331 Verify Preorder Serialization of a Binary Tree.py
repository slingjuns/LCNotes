// Date: September 1, 2022
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        self.nums = list(preorder.split(","))
        self.idx = 0
        def helper():
            if self.idx > len(self.nums) - 1: return False
            if self.nums[self.idx] == '#': 
                self.idx += 1
                return True
            self.idx += 1
            return helper() and helper()
        res = helper()
        return res and self.idx == len(self.nums)
