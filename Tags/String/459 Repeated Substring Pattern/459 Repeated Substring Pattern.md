# 459. Repeated Substring Pattern

Careful: No
Date: October 28, 2023
Difficulty: Easy
Index: 459
Programming Language: C++
Tags: Circular Array, String
Link: https://leetcode.com/problems/repeated-substring-pattern/

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if (t.substr(1, t.size() - 2).find(s) != -1) return true;
        return false;
    }
};
```