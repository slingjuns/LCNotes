# 1723. Find Minimum Time to Finish All Jobs

Careful: Yes
Date: November 14, 2023
Difficulty: Hard
Elegant Code (Template): DFS
Index: 1723
Programming Language: C++
Tags: DFS
Link: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/

```cpp
class Solution {
int res = INT_MAX;
vector<int> hours;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        hours.resize(k);
        dfs(jobs, 0, 0, 0);
        return res;
    }
    
    void dfs(vector<int>& jobs, int index, int used, int cur_max) {
        if(index == jobs.size()) {
            res = min(res, cur_max);
            return;
        }
        for(int i = 0; i < used; ++i) {
            if(hours[i] + jobs[index] >= res) continue;
            hours[i] += jobs[index];
            int tmp = cur_max;
            cur_max = max(cur_max, hours[i]);
            dfs(jobs, index+1, used, cur_max);
            hours[i] -= jobs[index];
            cur_max = tmp;
        }
        if(used + 1 <= hours.size()) {
            hours[used] += jobs[index];
            int tmp = cur_max;
            cur_max = max(cur_max, hours[used]);
            dfs(jobs, index+1, used+1, cur_max);
            cur_max = tmp;
            hours[used] -= jobs[index];
        }
    }
};
```