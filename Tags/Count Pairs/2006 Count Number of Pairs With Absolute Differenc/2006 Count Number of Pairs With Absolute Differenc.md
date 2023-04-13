# 2006. Count Number of Pairs With Absolute Difference K

Careful: No
Date: April 13, 2023
Difficulty: Easy
Index: 2006
Programming Language: C++
Tags: Count Pairs, Hash Table
Link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

class Solution {
public:
int countKDifference(vector<int>& nums, int k) {
// no sorting
unordered_map<int, int> count;
int res = 0;
for(auto num: nums) count[num]++;

```
    for (int i = 0; i < nums.size(); ++i) {
        int target = nums[i] - k;
        if(target == nums[i]) res += count[target]-1;
        else res += count[target];
    }
    return res;
}

```

};

## Sorting

```cpp
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] - k;
            res += count[target];
            count[nums[i]]++;
        }
        return res;
    }
};
```

## Non Sorting

```cpp
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // no sorting
        unordered_map<int, int> count;
        int res = 0;
        for(auto num: nums) count[num]++;
        
        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] - k;
            if(target == nums[i]) res += count[target]-1;
            else res += count[target];
        }
        return res;
    }
};
```