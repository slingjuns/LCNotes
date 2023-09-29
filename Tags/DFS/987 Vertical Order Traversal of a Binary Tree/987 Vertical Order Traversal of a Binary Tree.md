# 987. Vertical Order Traversal of a Binary Tree

Careful: Yes
Date: September 29, 2023
Difficulty: Hard
Index: 987
Programming Language: C++
Skills: 1. 注意细节, 可能出现duplicate values, 不能用set. 2. sort values on the same x-axis
Tags: Binary Tree, DFS
Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
private:
    map<int, map<int, vector<int>>> m;
    void dfs(TreeNode* root, int i, int j) {
        if(!root) return;
        m[j][i].push_back(root->val);
        dfs(root->left, i+1, j-1);
        dfs(root->right, i+1, j+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, 0);
        for(auto &[k,v]: m) {
            vector<int> tmp;
            for(auto &[ik, iv]: v) {
                sort(iv.begin(),iv.end());
                tmp.insert(tmp.end(), iv.begin(), iv.end());
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```