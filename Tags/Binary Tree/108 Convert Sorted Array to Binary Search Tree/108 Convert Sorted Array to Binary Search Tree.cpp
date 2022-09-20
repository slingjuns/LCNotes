// Date: September 20, 2022
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, nullptr, 0, nums.size());
    }
    
    TreeNode* dfs(vector<int>& nums, TreeNode* root, size_t start, size_t end) {
        if (start >= end) return nullptr;
        size_t mid = start + (end - start) / 2;
        TreeNode* tmp = new TreeNode(nums[mid]);
        tmp->left = dfs(nums, tmp, start, mid);
        tmp->right = dfs(nums, tmp, mid+1, end);
        return tmp;
    }
};
