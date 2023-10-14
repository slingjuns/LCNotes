# 503. Next Greater Element II

Careful: Yes
Date: October 14, 2023
Difficulty: Medium
Elegant Code (Template): Monotonic Stack, Stack
Index: 503
Programming Language: C++
Skills: 1. For circular arrays, loop twice
Tags: Monotonic Stack
Link: https://leetcode.com/problems/next-greater-element-ii/

```cpp
vector<int> nextGreaterElements(vector<int>& A) {
      int n = A.size();
      vector<int> stack, res(n, -1);
      for (int i = 0; i < n * 2; ++i) {
          while (stack.size() && A[stack.back()] < A[i % n]) {
              res[stack.back()] = A[i % n];
              stack.pop_back();
          }
          stack.push_back(i % n);
      }
      return res;
  }
```