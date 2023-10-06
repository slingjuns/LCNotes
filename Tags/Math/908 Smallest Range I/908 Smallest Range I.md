# 908. Smallest Range I

Careful: Yes
Date: October 6, 2023
Difficulty: Easy
Index: 908
Programming Language: C++
Tags: Math
Link: https://leetcode.com/problems/smallest-range-i/

```cpp
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mx = A[0], mn = A[0];
        for (int a : A) mx = max(mx, a), mn = min(mn, a);
        return max(0, mx - mn - 2 * K);
    }
};
```