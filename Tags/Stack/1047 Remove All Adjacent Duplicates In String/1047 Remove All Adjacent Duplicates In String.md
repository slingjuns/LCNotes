# 1047. Remove All Adjacent Duplicates In String

Careful: No
Date: September 25, 2022
Difficulty: Medium
Index: 1047
Programming Language: C++
Skills: 1. string 本身也是一种stack, 如果return type为 string 可以直接用string 当做stack
Tags: Stack, String
Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        // stack
        string res = "";
        for(int i = 0; i < s.length(); ++i) {
            bool pop = false;
            while(!res.empty() && res.back() == s[i]) {
                res.pop_back();
                pop = true;
            }
            if(!pop) res.push_back(s[i]);
        }
        return res;
    }
};
```