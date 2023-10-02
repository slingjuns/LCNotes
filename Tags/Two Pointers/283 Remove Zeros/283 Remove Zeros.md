# 283. Remove Zeros

Careful: Yes
Date: October 2, 2023
Difficulty: Medium
Elegant Code (Template): Fast Slow Pointer, Two Pointers
Index: 283
Programming Language: C++
Skills: 1. In-place, 快慢指针
Tags: Two Pointers
Link: https://leetcode.com/problems/move-zeroes/

## 循环不变量 Loop Invariant

1. **All elements before the slow pointer (lastNonZeroFoundAt) are non-zeroes.**
2. **All elements between the current and slow pointer are zeroes.**

Therefore, when we encounter a non-zero element, we need to swap elements pointed by current and slow pointer, then advance both pointers. If it's zero element, we just advance current pointer.

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // two pointers
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if(nums[fast] != 0) {
                swap(nums[slow++], nums[fast]);
            }
            fast++;
        }
    
    }
};
```

### Follow-up: Minimize total operations

- swap takes three operations

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) swap(nums[left++], nums[i]);
        }
    }
};
```