# 977. Squares of a Sorted Array

Careful: No
Date: September 25, 2022
Difficulty: Easy
Index: 977
Programming Language: C++
Tags: Left-Right-Pointers, Two Pointers
Link: https://leetcode.com/problems/squares-of-a-sorted-array/

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int left = 0, right = nums.size()-1;
        int index = nums.size()-1;
        while (left <= right) {
            int l_square = pow(nums[left], 2), r_square = pow(nums[right], 2);
            if (r_square > l_square) {
                right--;
                res[index--] = r_square;
            } else {
                left++;
                res[index--] = l_square;
            }
        }
        return res;
    }
};
```