# 1855. Maximum Distance Between a Pair of Values

Careful: No
Date: April 10, 2023
Difficulty: Medium
Index: 1855
Programming Language: C++
Tags: Binary Search, Count Pairs
Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

```cpp
class Solution {
public:
    bool formValidPairs(vector<int>& nums1, vector<int>& nums2, int dist) {
        for (int i = 0; i < nums1.size(); ++i) {
            if(i+dist < nums2.size() && nums1[i] <= nums2[i+dist]) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = nums2.size();
        while(l < r) {
            int mid = r - (r-l) / 2;
            if(formValidPairs(nums1, nums2, mid)) l = mid;
            else r = mid-1;
        } 
        return l;
    }
};
```