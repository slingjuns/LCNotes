# 84. Largest Rectangle in Histogram

Careful: Yes
Date: October 16, 2023
Difficulty: Hard
Elegant Code (Template): Monotonic Stack
Index: 84
Programming Language: C++
Skills: 1. 此题和container with most water不同，主要是找prev + next smaller, 即对于每个ith element, 找它作为最小值的区间
Tags: Monotonic Stack
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        // monotonic increasing stack, find left and right next smaller element
        h.push_back(0);
        deque<int> st;
        int res = 0;
        for(int i = 0; i < h.size(); ++i) {
            auto tmp = h[i];
            while(!st.empty() && h[st.back()] >= tmp) { // Increasing Stack
                auto cur_index = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                // i is the next smaller element for cur_index, st.back() is the prev smaller element for cur_index
                res = max(res, (i-left-1)*h[cur_index]);
            }
            st.push_back(i);
        }
        return res;
    }
};
```