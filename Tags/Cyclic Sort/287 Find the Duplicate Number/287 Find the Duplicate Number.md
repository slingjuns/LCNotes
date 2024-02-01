# 287. Find the Duplicate Number

Careful: No
Date: February 1, 2024
Difficulty: Medium
Index: 287
Programming Language: C++
Tags: Cyclic Sort
Link: https://leetcode.com/problems/find-the-duplicate-number/

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // cyclic sort
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) 
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != i+1) return nums[i];
        return -1;
    }
};
```