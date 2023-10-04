# 1347. Minimum Number of Steps to Make Two Strings Anagram

Careful: No
Date: October 4, 2023
Difficulty: Medium
Index: 1347
Programming Language: C++
Skills: 1. Anagram
Tags: Hash Table
Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

```cpp
class Solution {
public:
    int minSteps(string s, string t) {
        // equal length
        vector<int> h_s(26, 0), h_t(26, 0);
        for(int i = 0; i < s.length(); ++i) {
            h_s[s[i]-'a']++;
            h_t[t[i]-'a']++;
        }
        
        int res = 0;
        for(int i = 0; i < 26; ++i) {
            auto diff = h_t[i]-h_s[i];
            if(diff > 0) res += diff;
        }
        return res;
    }
    
    
};
```