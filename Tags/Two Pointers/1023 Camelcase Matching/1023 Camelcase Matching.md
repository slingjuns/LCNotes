# 1023. Camelcase Matching

Careful: No
Date: October 4, 2022
Difficulty: Medium
Index: 1023
Programming Language: C++
Skills: 1. 本质是查找subsequence, 结尾后需加一层条件判断有无大写字母
Tags: Two Pointers, Two Sequence
Link: https://leetcode.com/problems/camelcase-matching/

```cpp
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto str: queries) {
            int left = 0; int right = 0;
            while (left < str.length() && right < pattern.length()) {
                char s_left = str[left], r_left = pattern[right];
                if (s_left == r_left) {
                    left++; 
                    right++;
                } else {
                    if (isupper(s_left)) break;
                    left++;
                }
            }
            if (right == pattern.length() && find_if(str.begin()+left, str.end(), [](const char s){
                return isupper(s);
            }) == str.end()) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
```