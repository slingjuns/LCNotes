class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        def helper(root, cur_sum):
            if not root: return
            path_sum = cur_sum*10 + root.val
            if not root.left and not root.right:
                self.res += path_sum
                return
            helper(root.left, path_sum)
            helper(root.right, path_sum)
        helper(root, 0)
        return self.res
