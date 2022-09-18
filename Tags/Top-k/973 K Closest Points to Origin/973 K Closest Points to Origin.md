# 973. K Closest Points to Origin

Careful: Yes
Date: September 18, 2022
Difficulty: Medium
Index: 973
Programming Language: C++
Skills: Two methods to implement: 1. Customized sort 2: QuickSelect
Tags: QuickSelect, Sorting, Top-k
Link: https://leetcode.com/problems/k-closest-points-to-origin/

## Sort

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const auto &a1, const auto&a2){
            const auto d1 = pow(a1[0], 2) + pow(a1[1], 2);
            const auto d2 = pow(a2[0], 2) + pow(a2[1], 2);
            return d1 < d2;
        });
        vector<vector<int>> res(points.begin(), points.begin()+k);
        return res;
    }
};
```