# 392. Is Subsequence

Careful: No
Date: October 3, 2022
Difficulty: Easy
Elegant Code (Template): Two Pointers, Two Sequence
Index: 392
Programming Language: C++
Skills: 1. Two Pointers 2. let left pointer always point to shorter string or arrays(we can swap string if this is not guranteed)
Tags: Two Pointers, Two Sequence
Link: https://leetcode.com/problems/is-subsequence/

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0, right = 0;
        
        // if (t.length() < s.length()) swap(s, t);  // left string is always shorter than right
        while (left < s.length() && right < t.length()) {
            if (s[left] == t[right]) {
                left++;
                right++;
            } else {
                right++;
            }
        }
        return left >= s.length();
    }
};
```