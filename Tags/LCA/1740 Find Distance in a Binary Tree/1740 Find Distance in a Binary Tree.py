class Solution:
    def findDistance(self, root: Optional[TreeNode], p: int, q: int) -> int:
        def LCA(root, p, q):
            if not root:
                return None
            if root.val == p or root.val == q:
                return root
            left, right = LCA(root.left, p, q), LCA(root.right, p, q)
            if left and right:
                return root
            return left or right

        def dist(root, target):
            if not root:
                return float('inf')
            if root.val == target:
                return 0
            return min(dist(root.left, target), dist(root.right, target)) + 1
        lca = LCA(root, p, q)
        return dist(lca, p) + dist(lca, q)

