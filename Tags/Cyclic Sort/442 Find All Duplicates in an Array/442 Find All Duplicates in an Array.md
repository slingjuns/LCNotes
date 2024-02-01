# 442. Find All Duplicates in an Array

Careful: No
Date: February 1, 2024
Difficulty: Medium
Index: 442
Programming Language: C++
Tags: Cyclic Sort
Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // cyclic sort
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) 
                swap(nums[i], nums[nums[i]-1]);
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != i+1) res.push_back(nums[i]);
        return res;
    }
};
```