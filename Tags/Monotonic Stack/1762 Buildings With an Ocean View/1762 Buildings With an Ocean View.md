# 1762. Buildings With an Ocean View

Careful: No
Date: October 18, 2023
Difficulty: Medium
Index: 1762
Programming Language: C++
Skills: 1. Next Greater Element
Tags: Monotonic Stack
Link: https://leetcode.com/problems/buildings-with-an-ocean-view/

```cpp
class Solution {
public:
    vector<int> findBuildings(vector<int>& h) {
        vector<int> st; // next greater, monotonic decreasing
        for(int i = 0; i < h.size(); ++i) {
            while(!st.empty() && h[st.back()] <= h[i]) {
                st.pop_back();
            }
            st.push_back(i);
        }
        return st;
    }
};
```