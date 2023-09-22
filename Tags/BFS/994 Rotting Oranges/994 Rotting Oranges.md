# 994. Rotting Oranges

Careful: Yes
Date: September 22, 2023
Difficulty: Medium
Elegant Code (Template): BFS
Index: 994
Programming Language: C++
Tags: BFS
Link: https://leetcode.com/problems/rotting-oranges/

```cpp
class Solution {
using PII = pair<int, int>;
private:
    int res = INT_MAX;
    int moves_x[4] = {0,0,-1,1};
    int moves_y[4] = {-1,1,0,0};
public:
    int bfs(vector<vector<int>>& grid, deque<PII>& q, int count) {
        set<PII> visited(q.begin(), q.end());
        int levels = 0;
        int total = 0;
        if(q.size() == count) return 0;
        while (!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop_front();
                total++;
                if(total == count) return levels; // 这一步表示到达终点
                for (int m = 0; m < 4; ++m) {
                    int new_i = cur.first + moves_x[m], new_j = cur.second + moves_y[m];
                    if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && grid[new_i][new_j] != 0 && !visited.count({new_i, new_j})) {
                        visited.insert({new_i, new_j});
                        q.push_back({new_i, new_j});
                    }
                }
            }
            levels++;
        }
        return INT_MAX;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        // preprocess
        deque<PII> q;
        int count = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) q.push_back({i, j});
                if(grid[i][j] != 0) count++;
            }
        }
        
        res = bfs(grid, q, count);
        return res == INT_MAX ? -1 : res;
    }
};
```