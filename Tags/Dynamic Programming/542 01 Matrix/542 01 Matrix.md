# 542. 01 Matrix

Careful: No
Date: November 6, 2023
Difficulty: Medium
Elegant Code (Template): Dynamic Programming
Index: 542
Programming Language: C++
Skills: 1. 这道题提供了一个处理二维路径DP的新思路, 两次DP
Tags: Dynamic Programming
Link: https://leetcode.com/problems/01-matrix/

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // dp twice
        int m = mat.size(), n = mat[0].size(), INF = m+n;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) mat[i][j] = 0;
                else {
                    mat[i][j] = INF;
                    if(i-1 >= 0) mat[i][j] = min(mat[i][j], mat[i-1][j]+1);
                    if(j-1 >= 0) mat[i][j] = min(mat[i][j], mat[i][j-1]+1);
                }
            }
        }
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if(mat[i][j] == 0) mat[i][j] = 0;
                else {
                    if(i+1 < m) mat[i][j] = min(mat[i][j], mat[i+1][j]+1);
                    if(j+1 < n) mat[i][j] = min(mat[i][j], mat[i][j+1]+1);
                }
            }
        }
        return mat;
    }
};
```