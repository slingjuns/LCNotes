# 344. Reverse String

Careful: No
Date: October 5, 2022
Difficulty: Easy
Index: 344
Programming Language: C++
Tags: Left-Right-Pointers, Two Pointers
Link: https://leetcode.com/problems/reverse-string/

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
```