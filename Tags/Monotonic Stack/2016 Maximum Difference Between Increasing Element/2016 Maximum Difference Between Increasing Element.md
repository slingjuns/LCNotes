# 2016. Maximum Difference Between Increasing Elements

Careful: No
Date: October 2, 2023
Difficulty: Easy
Index: 2016
Programming Language: C++
Tags: Monotonic Stack
Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements/

```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // monotonic stack
        deque<int> st = {nums[0]};
        int res = -1;
        for(int i = 1; i < nums.size(); ++i) {
            auto num = nums[i];
            if(num > st.back()) {
                res = max(res, num-st[0]);
            } else {
                while(!st.empty() && st.back() >= num) st.pop_back();  
            }
            st.push_back(num);
        }
        return res;
    }
};
```