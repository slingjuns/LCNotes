// Date: October 9, 2023
class Solution {
using PII = pair<int,int>;
vector<PII> moves = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void dfs(vector<vector<int>>& grid, int row, int col) {
        if(grid[row][col] == 0) return;
        grid[row][col] = 0;
        for(auto move: moves) {
            int new_row = row+move.first, new_col = col+move.second;
            if(new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size())                  {
                dfs(grid, new_row, new_col);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            if(grid[i][0] == 1) dfs(grid, i, 0);
            if(grid[i][n-1] == 1) dfs(grid, i, n-1);
        }
        for(int i = 0; i < n; ++i) {
            if(grid[0][i] == 1) dfs(grid, 0, i);
            if(grid[m-1][i] == 1) dfs(grid, m-1, i);
        }
        // count 1
        int res = 0;
        for(auto row: grid) {
            for(auto num: row) {
                if(num == 1) res++;
            }
        }
        return res;
    }
};
