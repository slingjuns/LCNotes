# 1860. Incremental Memory Leak

Careful: Yes
Date: October 14, 2023
Difficulty: Medium
Elegant Code (Template): Simulation
Index: 1860
Programming Language: C++
Skills: 1. 刚开始觉得不能用simulation, 但其实可以，因为k是log(max(m1,m2))
Tags: Simulation
Link: https://leetcode.com/problems/incremental-memory-leak/

```cpp
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 0;
        while(max(memory1, memory2) >= i) {
            if(memory1 >= memory2) memory1 -= i;
            else memory2 -= i;
            i++;
        }
        vector<int> res(3,0);
        res[0] = i;
        res[1] = memory1;
        res[2] = memory2;
        return res;
    }
};
```