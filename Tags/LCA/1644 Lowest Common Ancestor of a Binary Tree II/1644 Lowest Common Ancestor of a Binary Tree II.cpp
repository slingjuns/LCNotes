// Date: February 3, 2023
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        def dfs(root, p, q, count):
            if not root:
                return None, count
            found = False
            if root == p or root == q:
                count = count-1
                found = True
            left, lc = dfs(root.left, p, q, count)
            right, rc = dfs(root.right, p, q, lc)
            if left and right or found: # the lowest common ancestor
                return root, rc
            return left or right, rc
        
        lca, count = dfs(root, p, q, 2)
        return lca if count == 0 else None
