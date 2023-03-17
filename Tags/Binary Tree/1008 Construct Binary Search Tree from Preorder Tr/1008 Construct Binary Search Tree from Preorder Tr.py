class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        self.idx = 0
        def helper(low_limit, high_limit):
            if self.idx >= len(preorder):
                return None
            root = None
            if preorder[self.idx] > low_limit and preorder[self.idx] < high_limit:
                root = TreeNode(val=preorder[self.idx])
                self.idx += 1
                root.left = helper(low_limit, root.val)
                root.right = helper(root.val, high_limit)
            return root
        return helper(float("-inf"), float("inf"))
