# 2038. Remove Colored Pieces if Both Neighbors are the Same Color

Careful: No
Date: November 3, 2023
Difficulty: Medium
Index: 2038
Programming Language: C++
Tags: Two Pointers
Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

```cpp
class Solution {
public:
    bool winnerOfGame(string colors) {
        // count how many rounds can I pick A == how many AAA
        int left = 0, count_A = 0, count_B = 0;
        for (int i = 0; i < colors.size();) {
            while(i < colors.size() && colors[i] == colors[left]) ++i;
            int count = max(0, i-left-2);
            if(colors[left] == 'A') count_A += count;
            else count_B += count;
            left = i;
        }
        return count_A > count_B;
    }
};
```