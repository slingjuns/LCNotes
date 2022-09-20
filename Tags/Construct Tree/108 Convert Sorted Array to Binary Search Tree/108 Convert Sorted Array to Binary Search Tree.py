// Date: September 20, 2022
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
