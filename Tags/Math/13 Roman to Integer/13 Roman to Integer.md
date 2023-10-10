# 13. Roman to Integer

Careful: No
Date: October 10, 2023
Difficulty: Easy
Elegant Code (Template): Math
Index: 13
Programming Language: C++
Skills: 1. Roman 字符存在减法时，不要比较roman character， 直接比较对应的integer, i.e. (m[ch] < m[s[i+1]])
Tags: Hash Table, Math
Link: https://leetcode.com/problems/roman-to-integer/

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int res = 0;
        for(int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(i <= s.length()-1 && m[ch] < m[s[i+1]]) res -= m[ch];
            else res += m[ch];
        }
        return res;
    }
};
```