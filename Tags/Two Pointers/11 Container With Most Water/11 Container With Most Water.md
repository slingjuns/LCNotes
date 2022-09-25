# 11. Container With Most Water

Careful: No
Date: September 25, 2022
Difficulty: Medium
Index: 11
Programming Language: C++
Tags: Left-Right-Pointers, Two Pointers
Link: https://leetcode.com/problems/container-with-most-water/

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxA = 0;
        while (left <= right) {
            int hl = height[left], hr = height[right];
            maxA = max(maxA, min(height[left], height[right])*(right-left));
            if (hl < hr) {
                while(left <= right && height[left] <= hl) {
                    left++;
                }
            } else {
                while (left <= right && height[right] <= hr) {
                    right--;
                }
            }
        }
        return maxA;
    }
};
```