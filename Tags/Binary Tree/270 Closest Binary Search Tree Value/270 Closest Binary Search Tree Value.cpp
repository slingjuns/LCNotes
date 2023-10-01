// Date: October 1, 2023
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
    int closestValue(TreeNode* root, double target) {
        auto cur = root;
        double minDiff = INT_MAX;
        int val = -1;
        while(cur) {
            double diff = abs(cur->val - target);
           
            if(diff < minDiff) {
                val = cur->val;
                minDiff = diff;
            }
            else if (diff == minDiff) val = min(val, cur->val);
            if(cur->val > target) cur = cur->left;
            else cur = cur->right;
        }
        return val;
    }
};
