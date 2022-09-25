# 905. Sort Array By Parity

Careful: No
Date: September 25, 2022
Difficulty: Easy
Index: 905
Programming Language: C++
Skills: 1. 分区
Tags: Left-Right-Pointers, Two Pointers
Link: https://leetcode.com/problems/sort-array-by-parity/

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left <= right && nums[left] % 2 == 0) left++;
            while (left <= right && nums[right] % 2 != 0) right--;
            if (left < right) swap(nums[left], nums[right]);
        }
        return nums;
    }
};
```