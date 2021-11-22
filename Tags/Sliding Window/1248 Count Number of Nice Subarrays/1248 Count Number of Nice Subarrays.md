# 1248. Count Number of Nice Subarrays

Careful: Yes
Date: November 22, 2021
Difficulty: Medium
Elegant Code (Template): Prefix-Sum, Sliding Window
Index: 1248
Programming Language: C++
Tags: Prefix-Sum, Sliding Window
Link: https://leetcode.com/problems/count-number-of-nice-subarrays/

```cpp
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int res = 0;
        int l = 0;
        int odds = 0;
        int pre = 0;
        // maintain a window with <= k odd numbers
        for(int i=0; i < nums.size(); i++){
            odds += nums[i] & 1;
            while(odds > k){
                odds -= nums[l++] & 1;
            }
            res += i+1-l;
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
```