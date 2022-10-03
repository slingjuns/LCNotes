# 1004. Max Consecutive Ones III

Careful: No
Date: October 3, 2022
Difficulty: Medium
Elegant Code (Template): Sliding Window
Index: 1004
Programming Language: C++
Skills: 1. Use queue to store all the indexes of 0
Tags: Sliding Window
Link: https://leetcode.com/problems/max-consecutive-ones-iii/

```python
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> zero_index;
        int left = 0, right = 0;
        int res = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) zero_index.push(right);
            if (zero_index.size() > k) {
                int jumpto = zero_index.front();
                left = jumpto+1;
                zero_index.pop();
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};
```