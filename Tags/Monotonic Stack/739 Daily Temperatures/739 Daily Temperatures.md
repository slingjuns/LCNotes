# 739. Daily Temperatures

Careful: No
Date: September 14, 2023
Difficulty: Medium
Index: 739
Programming Language: C++
Tags: Monotonic Stack
Link: https://leetcode.com/problems/daily-temperatures/

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st; // stores index, monotonic decreasing stack
        vector<int> res(temperatures.size());
        for(int i = 0; i < temperatures.size(); ++i) {
            auto temp = temperatures[i];
            while(!st.empty() && temperatures[st.back()] < temp) {
                auto j = st.back();
                res[j] = i-j;
                st.pop_back();
            }
            st.push_back(i);
        }
        while(!st.empty()) {
            auto j = st.back();
            res[j] = 0;
            st.pop_back();
        }
        return res;
    }
};
```