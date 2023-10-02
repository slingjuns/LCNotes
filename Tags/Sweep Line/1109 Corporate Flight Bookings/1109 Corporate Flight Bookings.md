# 1109. Corporate Flight Bookings

Careful: No
Date: October 2, 2023
Difficulty: Medium
Index: 1109
Programming Language: C++
Skills: 1. 注意区间结束应该+1 再进行操作
Tags: Sweep Line
Link: https://leetcode.com/problems/corporate-flight-bookings/

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0), res(n+1, 0);
        // initialize diff array
        for(auto booking: bookings) {
            auto i = booking[0], j = booking[1], k = booking[2];
            diff[i]+= k;
            diff[j+1]-= k;
        }
        
        auto sum = 0;
        for(int i = 1; i < res.size(); ++i) {
            sum += diff[i];
            res[i] = sum;
        }
        res.erase(res.begin());
        return res;
    }
};
```