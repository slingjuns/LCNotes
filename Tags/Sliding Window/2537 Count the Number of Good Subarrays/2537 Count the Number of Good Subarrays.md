# 2537. Count the Number of Good Subarrays

Careful: Yes
Date: April 14, 2023
Difficulty: Medium
Index: 2537
Programming Language: C++
Skills: 1. At least K maintain 满足at least k 条件的数组 2. 计数时所有以右边界再往后结尾的subarray 都满足条件
Tags: Sliding Window
Link: https://leetcode.com/problems/count-the-number-of-good-subarrays/

```cpp
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long window_k = 0;
        map<int, int> window;
        long long ans = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); ++i) {
            window_k += window[nums[i]];
            window[nums[i]]++;
            while(window_k >= k) {// 当前窗口一定满足条件，所有以在ith元素后面的元素（包括i）结尾的数组都可行
                ans += nums.size()-i;
                window_k -= (window[nums[l]]-1);
                window[nums[l]]--;
                l++;
            }
        }   
        return ans;
    }
};
```