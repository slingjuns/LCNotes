# 253. Meeting Rooms II

Careful: Yes
Date: September 16, 2022
Difficulty: Medium
Elegant Code (Template): Greedy, Interval
Index: 253
Programming Language: C++
Skills: 1. Similar to Interval Scheduling
Tags: Greedy, Interval
Link: https://leetcode.com/problems/meeting-rooms-ii/

```python
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int>Map;
        for (auto interval:intervals)
        {
            Map[interval[0]]+=1;
            Map[interval[1]]-=1;
        }
        
        int sum = 0;
        int ret = 0;
        for (auto& [t,diff]: Map)
        {
            sum += diff;
            ret = max(sum, ret);
        }
        return ret;
    }
};
```