# 387. First Unique Character in a String

Careful: No
Date: October 1, 2023
Difficulty: Easy
Index: 387
Programming Language: C++
Tags: Hash Table
Link: https://leetcode.com/problems/first-unique-character-in-a-string/

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> m(26, 0);
        for(char c: s) m[c-'a']++;
        
        for(int i = 0; i < s.length(); ++i) {
            if(m[s[i]-'a'] == 1) return i;
        }
        
        return -1;
    }
};
```