# 470. Implement Rand10() Using Rand7()

Careful: Yes
Date: October 3, 2023
Difficulty: Medium
Elegant Code (Template): Random, Rejection Sampling
Index: 470
Programming Language: C++
Skills: 公式 (randX() - 1) * X + (randX() - 1)
Tags: Random, Rejection Sampling
Link: https://leetcode.com/problems/implement-rand10-using-rand7/

```cpp
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // random 
        int rand48;
        do {
            rand48 = (rand7()-1) * 7 + rand7()-1; // 0-48
        } while(rand48 >= 40);
        int res = rand48 % 10;
        return res == 0 ? 10 : res;
    }
};
```