# 582. Kill Process

Careful: Yes
Date: September 29, 2022
Difficulty: Medium
Elegant Code (Template): DFS, Graph
Index: 582
Programming Language: C++
Skills: 1. no need to traverse all nodes: (we already know the target PID, so we can start from the target node in the graph.
Tags: DFS, Graph
Link: https://leetcode.com/problems/kill-process/

```cpp
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // 0: 3
        // 3: [1, 5]
        // 5: [10]
        unordered_map<int, vector<int>> graph; // graph
        for (int i = 0; i < ppid.size(); ++i) {
            auto pp = ppid[i];
            graph[pp].push_back(pid[i]);
        }
        // no need to traverse all nodes: (we already know the target pid, so we can start from there)
        vector<int> res;
        dfs(kill, res, graph);
        return res;
    }
    
    void dfs(int root, vector<int> &res, unordered_map<int, vector<int>> &graph){
        res.push_back(root);
        if (!graph.count(root)) return;
        for (auto child: graph[root]) {
            dfs(child, res, graph);
        }
    }
};
```