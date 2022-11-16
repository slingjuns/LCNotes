# 1590. Make Sum Divisible by P

Careful: Yes
Date: November 16, 2022
Difficulty: Medium
Elegant Code (Template): Overflow, Prefix-Sum
Index: 1590
Programming Language: C++
Skills: Be care with sum overflow
Tags: Prefix-Sum
Link: https://leetcode.com/problems/make-sum-divisible-by-p/

```go
class Solution {
public:
     int minSubarray(vector<int>& A, int p) {
        int n = A.size(), res = n, need = 0, cur = 0;
        for (auto a : A)
            need = (need + a) % p;
        unordered_map<int, int> last = {{0, -1}};
        for (int i = 0; i < n; ++i) {
            cur = (cur + A[i]) % p;
            last[cur] = i;
            int want = (cur - need + p) % p;
            if (last.count(want))
                res = min(res, i - last[want]);
        }
        return res < n ? res : -1;
    }
};
```