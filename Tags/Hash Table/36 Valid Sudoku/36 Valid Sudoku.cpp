// Date: February 4, 2024
class Solution {
unordered_map<int, set<int>> rows, cols, blocks;
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int digit = board[i][j]-'0';
                    // check rows
                    if(rows[i].count(digit)) return false;
                    // check columns
                    if(cols[j].count(digit)) return false;
                    rows[i].insert(digit);
                    cols[j].insert(digit);
                    int b_n = i / 3 * 3 + j / 3;
                    // check blocks
                    if(blocks[b_n].count(digit)) return false;
                    blocks[b_n].insert(digit);
                }
            }
        }
        return true;
    }
};
