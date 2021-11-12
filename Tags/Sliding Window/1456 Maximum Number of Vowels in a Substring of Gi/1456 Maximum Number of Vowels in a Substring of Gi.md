# 1456. Maximum Number of Vowels in a Substring of Given Length

Careful: No
Date: November 12, 2021
Difficulty: Medium
Index: 1456
Programming Language: C++
Tags: Sliding Window
Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

```python
class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        ans = cnt = 0
        for i, c in enumerate(s):
            if c in vowels:
                cnt += 1
            if i >= k and s[i - k] in vowels:
                cnt -= 1
            ans  = max(cnt, ans)
        return ans
```