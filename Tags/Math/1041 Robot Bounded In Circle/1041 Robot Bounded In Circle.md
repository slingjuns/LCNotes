# 1041. Robot Bounded In Circle

Careful: Yes
Date: October 6, 2023
Difficulty: Medium
Index: 1041
Programming Language: C++
Skills: 1. vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}}; 
Tags: Math
Link: https://leetcode.com/problems/robot-bounded-in-circle/

```cpp
class Solution {
using PII = pair<int,int>;
public:
    bool isRobotBounded(string instructions) {
        // change direction + change position => circle
        int x = 0, y = 0, i = 0;
        **vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        for (char & ins : instructions)
            if (ins == 'R')
                i = (i + 1) % 4;
            else if (ins == 'L')
                i = (i + 3) % 4;**
            else
                x += d[i][0], y += d[i][1];
        return x == 0 && y == 0 || i > 0;
    }
};
```