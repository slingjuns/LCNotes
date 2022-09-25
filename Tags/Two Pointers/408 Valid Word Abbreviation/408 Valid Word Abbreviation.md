# 408. Valid Word Abbreviation

Careful: No
Date: September 25, 2022
Difficulty: Easy
Elegant Code (Template): Two Pointers, stringstream
Index: 408
Programming Language: C++
Skills: 1. stringstream can be used to represent the pointer when traversing the string
Tags: Two Pointers, Two Sequence
Link: https://leetcode.com/problems/valid-word-abbreviation/

```cpp
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        stringstream ss(abbr);
        int l1 = 0, l2 = 0;
        int tmp = 0;
        while (l1 < word.length() && ss.rdbuf()->in_avail()) {
            char ch = word[l1], abbr_ch = ss.peek();
            if (!isdigit(abbr_ch) && ch != abbr_ch) return false;
            if (isdigit(abbr_ch)) {
                if (abbr_ch == '0') return false;
                ss >> tmp;
                l1 += tmp;
            } else {
                ss >> abbr_ch;
                l1++;
            }
        }
        return l1 == word.length() && !ss.rdbuf()->in_avail();
    }
};
```