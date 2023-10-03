# 443. String Compression

Careful: Yes
Date: October 3, 2023
Difficulty: Medium
Elegant Code (Template): Fast Slow Pointer, Two Pointers
Index: 443
Programming Language: C++
Tags: Fast Slow Pointer, Two Pointers
Link: https://leetcode.com/problems/string-compression/

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int slow = 0, fast = 0;
        while (fast < chars.size()) {
            char prev = chars[fast];
            int prev_index = fast;
            while(fast < chars.size() && chars[fast] == prev) fast++;
            auto diff = fast-prev_index;
            chars[slow++] = prev;
            if(diff > 1) {
                for(char digit : to_string(diff)) chars[slow++] = digit;
            }
        }
        return slow;
    }
};
```