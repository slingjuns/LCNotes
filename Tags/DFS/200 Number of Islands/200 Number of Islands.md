# 200. Number of Islands

Careful: No
Date: September 21, 2023
Difficulty: Medium
Elegant Code (Template): DFS
Index: 200
Programming Language: C++
Tags: DFS
Link: https://leetcode.com/problems/number-of-islands/

```cpp
class Solution {
private:
    int ans;
    int move_x[4] = {-1, 1, 0, 0};
    int move_y[4] = {0, 0, -1, 1};
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(int d = 0; d < 4; ++d) {
            auto new_i = i + move_x[d], new_j = j + move_y[d];
            if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size()) 
                dfs(grid, new_i, new_j);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
```