# 212. Word Search II

Careful: Yes
Date: November 14, 2023
Difficulty: Hard
Elegant Code (Template): DFS, Trie
Index: 212
Programming Language: C++
Skills: 1. Trie上dfs
Tags: DFS, Trie
Link: https://leetcode.com/problems/word-search-ii/

## Naive DFS with prefix pruning

```cpp
class Solution {
unordered_set<string> res;
int moves_x[4] = {-1,0,1,0}, moves_y[4] = {0,1,0,-1};
unordered_set<string> prefix;
unordered_set<string> words;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& w) {
        // generate all prefix
        for(auto str: w) {
            for(int i = 1; i <= str.length(); ++i) {
                prefix.insert(str.substr(0, i));
            }
            words.insert(str);
        }
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                string tmp;
                char ch = board[i][j];
                tmp += ch;
                board[i][j] = '.';
                if(prefix.count(tmp)) dfs(board, i, j, tmp);
                board[i][j] = ch;
            }
        }
        vector<string> v_res(res.begin(), res.end());
        return v_res;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, string& cur) {
        if(words.count(cur)) res.insert(cur);
        for(int k = 0; k < 4; ++k) {
            int new_i = i + moves_x[k], new_j = j + moves_y[k];
            if(new_i < 0 || new_i >= board.size() || new_j < 0 || new_j >= board[0].size()) continue; // out of bound
            if(board[new_i][new_j] == '.') continue; // visited
            char ch = board[new_i][new_j];
            if(!prefix.count(cur+ch)) continue; // prune
            cur = cur + ch;
            board[new_i][new_j] = '.';
            dfs(board, new_i, new_j, cur);
            board[new_i][new_j] = cur.back();
            cur.pop_back();
        }
    }
};
```

## DFS on Trie

```cpp
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        WORD_KEY = '$'
        
        trie = {}
        for word in words:
            node = trie
            for letter in word:
                # retrieve the next node; If not found, create a empty node.
                node = node.setdefault(letter, {})
            # mark the existence of a word in trie node
            node[WORD_KEY] = word
        
        rowNum = len(board)
        colNum = len(board[0])
        
        matchedWords = []
        
        def backtracking(row, col, parent):    
            
            letter = board[row][col]
            currNode = parent[letter]
            
            # check if we find a match of word
            word_match = currNode.pop(WORD_KEY, False)
            if word_match:
                # also we removed the matched word to avoid duplicates,
                #   as well as avoiding using set() for results.
                matchedWords.append(word_match)
            
            # Before the EXPLORATION, mark the cell as visited 
            board[row][col] = '#'
            
            # Explore the neighbors in 4 directions, i.e. up, right, down, left
            for (rowOffset, colOffset) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
                newRow, newCol = row + rowOffset, col + colOffset     
                if newRow < 0 or newRow >= rowNum or newCol < 0 or newCol >= colNum:
                    continue
                if not board[newRow][newCol] in currNode:
                    continue
                backtracking(newRow, newCol, currNode)
        
            # End of EXPLORATION, we restore the cell
            board[row][col] = letter
        
            # Optimization: incrementally remove the matched leaf node in Trie.
            if not currNode:
                parent.pop(letter)

        for row in range(rowNum):
            for col in range(colNum):
                # starting from each of the cells
                if board[row][col] in trie:
                    backtracking(row, col, trie)
        
        return matchedWords
```