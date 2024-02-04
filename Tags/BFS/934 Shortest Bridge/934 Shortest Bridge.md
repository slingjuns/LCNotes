# 934. Shortest Bridge

Careful: Yes
Date: February 4, 2024
Difficulty: Medium
Elegant Code (Template): BFS, DFS
Index: 934
Programming Language: C++
Skills: 1. 连通性DFS + 多源BFS, 写对比较困难
Tags: BFS, DFS
Link: https://leetcode.com/problems/shortest-bridge/

```cpp
class Solution {
using PII = pair<int,int>;
private:
    vector<vector<int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        using Node = vector<int>;
        deque<Node> q;
        
        bool found = false;
        // dfs
        for(int i = 0; i < grid.size(); ++i) {
            if(found) break;
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    dfs(grid, visited, i, j);
                    found = true;
                    break;
                }
            }
        }
        // bfs
        set<Node> bfs_visited;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    q.push_back({i,j,0});
                    bfs_visited.insert({i,j});
                }
            }
        }
        while(!q.empty()) {
            for(int s = 0; s < q.size(); ++s) {
                int i = q.front()[0], j = q.front()[1], count = q.front()[2];
                q.pop_front();
                if(grid[i][j] == 1) return count;
                for(int k = 0; k < 4; ++k) {
                    int new_i = i + moves[k][0], new_j = j + moves[k][1];
                    if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size()) {
                        int new_count = grid[new_i][new_j] == 0 ? count+1 : count;
                        if(!bfs_visited.count({new_i, new_j})) {
                            q.push_back({new_i, new_j, new_count});
                            bfs_visited.insert({new_i, new_j});
                        }
                    }
                }
            }
            
        }
        return -1;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(grid[i][j] == 0) return;
        grid[i][j] = 2;
        for(int k = 0; k < 4; ++k) {
            int new_i = i + moves[k][0], new_j = j + moves[k][1];
            if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j])              {
                visited[i][j] = true;
                dfs(grid, visited, new_i, new_j);
            }
        }
    }
};
```