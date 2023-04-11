class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.res = 0
        def helper(root, cur_max):
            if not root: return
            if root.val >= cur_max:
                cur_max = root.val
                self.res += 1
            helper(root.left, cur_max)
            helper(root.right, cur_max)
        helper(root, root.val)
        return self.res

