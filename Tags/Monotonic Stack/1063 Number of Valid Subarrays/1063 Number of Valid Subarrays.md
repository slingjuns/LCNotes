# 1063. Number of Valid Subarrays

Careful: No
Date: October 16, 2023
Difficulty: Hard
Index: 1063
Programming Language: C++
Skills: 1. 对于每个ith element, 找多少个含有它的subarray是valid， 也就是找(他作为最小值)next smaller element
Tags: Monotonic Stack
Link: https://leetcode.com/problems/number-of-valid-subarrays/

```cpp
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        // for each ith element, find its next smaller
        nums.push_back(-1);
        deque<int> st;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            while(!st.empty() && nums[st.back()] > nums[i]) { // next smaller
                res += i-st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        return res;
    }
};
```