# 525. Contiguous Array

Careful: Yes
Date: April 11, 2023
Difficulty: Medium
Elegant Code (Template): Hash Table
Index: 525
Programming Language: C++
Skills: 1. 注意presum为0的初始值为-1
Tags: Hash Table, Prefix-Sum
Link: https://leetcode.com/problems/contiguous-array/

我们需要快速找到之前出现的相同的子数组和，因此我们可以使用哈希表来存储每个子数组和以及其最早出现的位置。如果我们再次遇到相同的子数组和，我们可以通过之前存储的位置计算当前子数组的长度并更新最大长度。因此，使用哈希表是解决这个问题的一种自然方式。

```python
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> prefix2index;
        int presum = 0;
        int res = 0;
        prefix2index[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            presum += (nums[i] ? 1 : -1);
            if(prefix2index.count(presum)) {
                res = max(i - prefix2index[presum], res);
            } else {
                prefix2index[presum] = i;
            }
        }
        return res;
    }
};
```

、