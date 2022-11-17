# 356. Line Reflection

Careful: Yes
Date: November 17, 2022
Difficulty: Medium
Index: 356
Programming Language: C++
Skills: 1. Midline is formed by the pair with min and max point
Tags: Hash Table, Two Pointers
Link: https://leetcode.com/problems/line-reflection/

```go
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int len = points.size();
        if (len==0 || len==1) return true;

        unordered_map<int, set<int>> mp;
        int max = points[0][0], min = points[0][0];
        // build the map, find min and max
        for (int i=0; i<len; ++i) {
            if (points[i][0] < min) min = points[i][0];
            if (points[i][0] > max) max = points[i][0];
            mp[points[i][1]].insert(points[i][0]);
        }
        double line = (min + max) / 2.0;

        // mirror the sorted x value in the set using two pointer
        for (auto it = mp.begin(); it!=mp.end(); ++it) {
            set<int>& s = it->second;
            for (auto start=s.begin(), end = s.end(); start!=end; ++start)  {
                if ((*start + *(--end)) / 2.0 != line)
                    return false;
                if (start==end) break;
            }
        }
        return true;
    }
};
```