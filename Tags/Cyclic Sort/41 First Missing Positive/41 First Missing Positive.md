# 41. First Missing Positive

Careful: Yes
Date: October 20, 2023
Difficulty: Hard
Elegant Code (Template): Cyclic Sort, Sorting
Index: 41
Programming Language: C++
Skills: 1. Indexing Sort经典题
Tags: Cyclic Sort, Sorting
Link: https://leetcode.com/problems/first-missing-positive/

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        nums.insert(nums.begin(),0);
        for (int i=0; i<nums.size(); i++)
        {
            while (nums[i]!=i && nums[i]<nums.size() && nums[i]!=nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        for (int i=1; i<nums.size(); i++)
            if (nums[i]!=i) return i;     
        
        return nums.size();
    }
};
```

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& A)
    {
        int n = A.size();
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};
```