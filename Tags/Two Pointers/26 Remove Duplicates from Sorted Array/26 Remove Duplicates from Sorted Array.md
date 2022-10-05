# 26. Remove Duplicates from Sorted Array

Careful: No
Date: October 5, 2022
Difficulty: Easy
Elegant Code (Template): Fast Slow Pointer, Two Pointers
Index: 26
Programming Language: C++
Skills: 1. In fast-slow pointer algorithm, we constantly move the fast pointer 
Tags: Fast Slow Pointer, Two Pointers
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;
        int count = 0;
        while (fast < nums.size()) {
            int prev = nums[fast];
            while(fast < nums.size() && nums[fast] == prev) fast++;
            nums[slow++] = prev;
        }
        return slow;
    }
};
```