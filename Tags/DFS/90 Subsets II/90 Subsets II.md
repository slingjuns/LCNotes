# 90. Subsets II

Careful: No
Date: November 12, 2023
Difficulty: Medium
Elegant Code (Template): DFS
Index: 90
Programming Language: C++
Tags: DFS
Link: https://leetcode.com/problems/subsets-ii/

```cpp
class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, vector<int>& path, int cur) {
        if(cur > nums.size()) {
            return;
        }
        res.push_back(path);
        for(int i = cur; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, path, i+1);
            path.pop_back();
            // skip duplicates
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> p;
        dfs(nums, p, 0);
        return res;
    }
};
```