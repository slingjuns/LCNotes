# 3. Longest Substring Without Repeating Characters

Careful: Yes
Date: October 3, 2022
Difficulty: Medium
Elegant Code (Template): Sliding Window
Index: 3
Programming Language: C++
Skills: 1. Use hashmap to record the last seen index of a character
Tags: Sliding Window
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

```python
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
```