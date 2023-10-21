# 7. Reverse Integer

Careful: Yes
Date: October 21, 2023
Difficulty: Medium
Elegant Code (Template): Math
Index: 7
Programming Language: C++
Tags: Math
Link: https://leetcode.com/problems/reverse-integer/

这是一道简单题，但是依然有两个知识点需要掌握。

- 首先，要记住INT_MIN=-2^31，对它去绝对值的话是会溢出整形的。所以对一个任意整形取绝对值的时候一定要考虑它是否可能是INT_MIN。
- **其次，如果快速判断一个数字在进位的过程中是否溢出？比如说如何判断`x*10 > INT_MAX`？其实交换一下位置，用`if (x > INT_MAX/10)`就巧妙地规避溢出报错的问题。**

```cpp
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int tmp = abs(x);
        int res = 0;
        while (tmp){
            if(res > INT_MAX/10 ) return 0;
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        if(x < 0) res *= -1;
        return res;
    }
};
```