# 452. Minimum Number of Arrows to Burst Balloons

Careful: No
Date: September 16, 2022
Difficulty: Medium
Index: 452
Programming Language: C++
Skills: 1. Similar to interval scheduling 
Tags: Greedy, Interval
Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

```python
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // greedy based on end time
        // sort
        sort(points.begin(), points.end(), [](const auto &a1, const auto &a2) {
            return a1[1] < a2[1];
        });
        // pick overlapping intervals
        int count = 1;
        int shortest_arrow = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > shortest_arrow || points[i][1] < shortest_arrow) {
                shortest_arrow = points[i][1];
                count++;
            }
        }
        return count;
    }
};
```