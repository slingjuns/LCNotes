# 808. Soup Servings

Careful: Yes
Date: October 6, 2023
Difficulty: Medium
Index: 808
Programming Language: C++
Skills: 1.  0 ≤ N ≤ 10^9, 按理说不能用memoization
2. N > 5000 (可以是其他数)， return 1
Tags: Dynamic Programming
Link: https://leetcode.com/problems/soup-servings/

## 重难点

- 三个边界条件
- **为什么n越大, probability越趋近于1**
    - A 每次操作减少的Expected Value = (100 + 75 + 50 + 25) * 0.25 = 75
    - B 每次操作减少的Expected Value = (0 + 25 + 50 + 75) * 0.25 = 37.5

```cpp
class Solution {
    map<pair<int,int>, double> dp;
public:
    double memo(int A, int B) {
        if(A <= 0 && B > 0) return 1;
        if(A <= 0 && B <= 0) return 0.5;
        if(A > 0 && B <= 0) return 0;
        if(dp.count({A,B})) return dp[{A,B}];
        dp[{A,B}] = 0.25 *  (memo(A-100, B) + memo(A-75, B-25) + memo(A-50, B-50) + memo(A-25, B-75));
        return dp[{A,B}];
    }
    
    double soupServings(int n) {
        if (n>5000) return 1;
        return memo(n, n);
    }
};
```