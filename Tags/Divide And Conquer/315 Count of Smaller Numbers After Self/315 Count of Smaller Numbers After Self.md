# 315. Count of Smaller Numbers After Self

Careful: Yes
Date: October 20, 2023
Difficulty: Hard
Elegant Code (Template): Divide And Conquer, Sorting
Index: 315
Programming Language: C++
Skills: 1. 原来的index会被打乱,需要copy一份原来数组
Tags: Divide And Conquer, Sorting
Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

```cpp
class Solution {
private:
    vector<int> res;
public:
    vector<int> countSmaller(vector<int>& nums) {
        res.resize(nums.size(), 0);
        vector<int> nums_copy = nums;
        mergeSort(nums, nums_copy, 0, nums.size()-1);
        return res;
    }
    
    void mergeSort(vector<int>& nums, vector<int>& nums_copy, int l, int r) {
        if(l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, nums_copy, l, mid);
        mergeSort(nums, nums_copy, mid+1, r);
        // count how many numbers on the right is smaller than self
        for(int j = l; j <= mid; ++j) {
           auto it = lower_bound(nums.begin()+mid+1, nums.begin()+r+1, nums_copy[j]);
           res[j] += it-(nums.begin()+mid+1);
        }
        // in-place merge
        inplace_merge(nums.begin()+l, nums.begin()+mid+1, nums.begin()+r+1);
    }
```