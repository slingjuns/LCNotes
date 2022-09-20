# 108. Convert Sorted Array to Binary Search Tree

Careful: No
Date: September 20, 2022
Difficulty: Easy
Index: 108
Programming Language: C++
Skills: 1. Pass index (Not the partitioned array) into recursion
2. Use left and right to identify the start of end of the array 
Tags: Binary Tree, Construct Tree
Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

```python
class Solution:
	def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
		def helper(low, high):
			if low >= high: return None
			root_idx = (low + high) // 2
			root = TreeNode(nums[root_idx])
			root.left = helper(low, root_idx)
			root.right = helper(root_idx+1, high)
			return root
		return helper(0, len(nums))
```

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
```