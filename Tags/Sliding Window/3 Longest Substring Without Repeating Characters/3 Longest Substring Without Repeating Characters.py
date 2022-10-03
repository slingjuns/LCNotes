// Date: October 3, 2022
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        used = {} # stores the location of characters in the window
        result = 0
        start = 0 
        
        for i, char in enumerate(s):
            if char in used and start <= used[char]:
                start = used[char] + 1
            else:
                result = max(result, i - start + 1)
                
            used[char] = i
        
        
        return result
