# 796. Rotate String

Careful: No
Date: October 28, 2023
Difficulty: Easy
Elegant Code (Template): Circular Array, String
Index: 796
Programming Language: C++
Tags: Circular Array, Rolling Hash, String
Link: https://leetcode.com/problems/rotate-string/

- 可以使用rolling hash 优化为(O(n))

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        // "cedabcdeab"
        if(s.length() != goal.length()) return false;
        goal = goal + goal;
        for(int i = 0; i+s.length()-1 < goal.length(); ++i) {
            auto tmp = goal.substr(i, s.length());
            if(tmp == s) return true;
        }
        return false;
    }
};
```