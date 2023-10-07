# 338. Counting Bits

Careful: No
Date: October 7, 2023
Difficulty: Easy
Elegant Code (Template): Bit-Manipulation, Dynamic Programming
Index: 338
Programming Language: C++
Tags: Bit-Manipulation, Dynamic Programming, 基本型II
Link: https://leetcode.com/problems/counting-bits/

## Compiler Builtin Functions

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i = 0; i < res.size(); ++i) {
            res[i] = __builtin_popcount(i);
        }
        return res;
    }
};
```

## DP

```cpp
class Solution {
private:
    vector<int> dp;
public:
    vector<int> countBits(int n) {
        dp.resize(n+1);
        for(int i = 1; i < dp.size(); ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
```