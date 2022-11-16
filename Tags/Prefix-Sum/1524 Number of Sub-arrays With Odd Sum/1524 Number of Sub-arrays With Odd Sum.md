# 1524. Number of Sub-arrays With Odd Sum

Careful: No
Date: November 16, 2022
Difficulty: Medium
Index: 1524
Programming Language: C++
Tags: Prefix-Sum
Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

```go
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // [1,3,5] => [1, 4, 9] (all subarr: 1, 3, 5, [1,3], [3,5], [1,3,5])
        vector<int> prefix(2, 0);
        prefix[0] = 1;
        int sum = 0, res = 0;
        long M = 1e9 + 7;
        for (auto num : arr) {
            sum += num;
            if (sum % 2 == 0) res = (res + prefix[1]) % M;
            else res = (res + prefix[0]) % M;
            prefix[sum % 2]++;
        }
        return res;
    }
};
```