# 409. Longest Palindrome

Careful: Yes
Date: October 2, 2022
Difficulty: Easy
Index: 409
Programming Language: C++
Skills: 注意，出现了奇数次的字符也可以参与构建回文串：其中一个可以全部采用；剩余的只需要取用其偶数次.
Tags: Hash Table
Link: https://leetcode.com/problems/longest-palindrome/

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        map<char, int> cache;
        for (auto ch: s) {
            cache[ch]++;
        }
        int flag = 0;
        for (auto [k, v]: cache){
            if (v % 2 == 0) res += v;
            else {
                res += v-1;
                flag = 1;
            }
        }
        return res+flag;
    }
};
```