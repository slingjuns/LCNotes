# 1326. Minimum Number of Taps to Open to Water a Garden

Careful: Yes
Date: November 20, 2022
Difficulty: Hard
Elegant Code (Template): Greedy, Interval
Index: 1326
Programming Language: C++
Skills: 1. sort by start and then end 2. among all intervals that overlap with the current, only pick the interval that reaches the furthest (this is not skipping overlapped intervals)
Tags: Greedy, Interval
Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<vector<int>> intervals;
        // construct intervals
        for (int i = 0; i < ranges.size(); ++i) intervals.push_back({max(0, i-ranges[i]), min(n, i+ranges[i])});
        
        sort(intervals.begin(), intervals.end(), [](const auto &v1, const auto &v2){
            return v1[0] < v2[0];
        });
        
        int count = 0, covered_til = 0, i = 0;
        while (i < intervals.size()) {
            int max_cover = covered_til;
            while (i<intervals.size() && intervals[i][0] <= covered_til) {											        		  
                max_cover = max(max_cover, intervals[i][1]);
                i++;
            }
            if (max_cover <= covered_til) return -1;
            count++;
            covered_til = max_cover;
		    if (covered_til >= n) return count;
        }
        
        return count;
    }
};
```