// Date: September 22, 2022
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
public:
    TreeNode* str2tree(string s) {
        stringstream ss(s);
        return dfs(ss);
    }
    
    TreeNode* dfs(stringstream &ss) {
        if (ss.peek() == -1) return nullptr;
        char buf;
        int val; 
        ss >> val;
        
        TreeNode* tmp = new TreeNode(val);
        if (ss.peek() == int('(')) {
            ss >> buf; // skip first "("
            tmp->left = dfs(ss);
            ss >> buf; // skip last ")"
        }
        if (ss.peek() == int('(')) {
            ss >> buf;  // skip first "("
            tmp->right = dfs(ss);
            ss >> buf;  // skip last ")"
        }
        return tmp;
    }
};
