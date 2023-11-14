# 37. Sudoku Solver

Careful: No
Date: November 14, 2023
Difficulty: Hard
Elegant Code (Template): DFS
Index: 37
Programming Language: C++
Skills: 1. 可行性剪枝
Tags: DFS
Link: https://leetcode.com/problems/sudoku-solver/

```cpp
class Solution {
using PII = pair<int,int>;
unordered_map<int, set<int>> rows, cols, blocks;
vector<PII> slots;
public:
    void solveSudoku(vector<vector<char>>& board) {
        // preprocess
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int digit = board[i][j]-'0';
                    rows[i].insert(digit);
                    cols[j].insert(digit);
                    int b_n = i / 3 * 3 + j / 3;
                    blocks[b_n].insert(digit);
                } else {
                    slots.emplace_back(i,j);
                }
            }
        }
        dfs(board, 0);
    }
    
    bool dfs(vector<vector<char>>& board, int index) {
        if(index == slots.size()) return true;
        for(int num = 1; num <= 9; ++num) {
            auto [i, j] = slots[index];
            int b_n = i / 3 * 3 + j / 3;
            if(rows[i].count(num) || cols[j].count(num) || blocks[b_n].count(num)) continue;
            board[i][j] = num + '0';
            rows[i].insert(num);
            cols[j].insert(num);
            blocks[b_n].insert(num);
            if(dfs(board, index+1)) return true;
            board[i][j] = '.';
            rows[i].erase(num);
            cols[j].erase(num);
            blocks[b_n].erase(num);
        }
        return false;
    }
};
```