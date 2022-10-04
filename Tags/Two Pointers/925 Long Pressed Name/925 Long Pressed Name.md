# 925. Long Pressed Name

Careful: No
Date: October 4, 2022
Difficulty: Easy
Index: 925
Programming Language: C++
Tags: Two Pointers, Two Sequence
Link: https://leetcode.com/problems/long-pressed-name/

```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int left = 0, right = 0;
        while (left < name.length() && right < typed.length()) {
            if (name[left] != typed[right]) return false;
            left++; right++;
            int count_left = 0, count_right = 0;
            while (left > 0 && left < name.length() && name[left] == name[left-1]) {
                count_left++;
                left++;
            }
            while (right > 0 && right < typed.length() && typed[right] == typed[right-1]) {
                count_right++;
                right++;
            }
            if (count_right < count_left) return false;
        }
        return left == name.length() && right == typed.length();
    }
};
```