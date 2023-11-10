# 39. Combination Sum

Careful: Yes
Date: November 10, 2023
Difficulty: Medium
Elegant Code (Template): DFS
Index: 39
Programming Language: C++
Tags: DFS
Link: https://leetcode.com/problems/combination-sum/

```cpp
class Solution {
vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, 0, 0, path, target);
        return res;
    }
    
    void dfs(vector<int>& candidates, int cur, int cur_sum, vector<int>& path, int target) {
        if(cur_sum == target) {
            res.push_back(path);
            return;
        }
        for(int i = cur; i < candidates.size(); ++i) {
            int buf = cur_sum;
            for(int k = 1; cur_sum+k*candidates[i] <= target; k++) {
                path.insert(path.end(), k, candidates[i]);
                cur_sum = cur_sum+k*candidates[i];
                dfs(candidates, i+1, cur_sum, path, target);
                cur_sum = buf;
                for(int j = 0; j < k; j++) path.pop_back();
            }
        }
    }
};
```