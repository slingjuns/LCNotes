# 532. K-diff Pairs in an Array

Careful: No
Date: April 14, 2023
Difficulty: Medium
Index: 532
Programming Language: C++
Tags: Count Pairs, Hash Table
Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

## Sorting

- res += 1 的方式避免重复pair

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> count;
        int res = 0;
        for(int i = 0; i < nums.size();) {
            int target = nums[i] - k;
            if(count[target] > 0) {
                res += 1;
                while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
            }
            count[nums[i]]++;
            i++;
        }
        return res;
    }
};
```

## Non-Sorting (Map)

- 每次不加count[nums[i]]

```cpp
1. USING MAPS :
We are aware of the fact that for a pair to be counted as an answer , both the elements ( x and x+k ) , need to be in the array.
So we simply create a map and store the frequency of each element in the map.
Now we traverse the map and for each element 'x' , we check if 'x+k' exists in the map . If it does , then it means a unique pair can be formed and hence, we increment the answer.

EDGE CASE :
The only edge case is the situation wherek=0. If k=0 , instead of finding 'x+k' , we check if the frequency of 'x'>1. If it is , then weincrement the answer .
Else , we don't increment the answer , as the frequency of x=1 and hence it can't form a pair with itself.

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int num:nums) count[num]++;
        int res=0;
        for(auto [num, freq]:count)
        {
            if(k==0)
            {    
                if(freq>1)
                res++;
            }
            else if(count.count(num+k))
                res++;
        }
        
        return res;
    }
};
```