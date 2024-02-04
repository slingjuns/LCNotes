# 168. Excel Sheet Column Title

Careful: Yes
Date: February 4, 2024
Difficulty: Easy
Index: 168
Programming Language: C++
Tags: String
Link: https://leetcode.com/problems/excel-sheet-column-title/

```cpp
class Solution {
public:
    string convertToTitle(int n) {

        string res;
        char tmp;
        while(n){
            n--;
            tmp = 'A' + n % 26;
            res = tmp + res;
            n /= 26;
        }
        return res;

    }
};
```