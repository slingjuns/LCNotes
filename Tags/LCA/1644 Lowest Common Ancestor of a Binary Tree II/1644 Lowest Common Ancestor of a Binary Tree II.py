// Date: September 21, 2022
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        def LCA(root, p, q):
            if not root:
                return None
            if root.val == q.val or root.val == p.val:
                return root
            left = LCA(root.left, p, q)
            right = LCA(root.right, p, q)
            if left and right:
                return root
            return left if left else right
        
        def contains(root, p):
            if not root: return False
            if root == p: return True
            return contains(root.left, p) or contains(root.right, p)
        if not contains(root, p) or not contains(root, q): return None
        return LCA(root,p,q)
