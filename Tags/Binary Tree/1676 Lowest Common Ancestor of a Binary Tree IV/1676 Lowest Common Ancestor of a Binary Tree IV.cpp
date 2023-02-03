// Date: February 3, 2023
class Solution(object):
    def dfs(self, root, nodes):
        if not root:
            return None
        if root in nodes:
            return root
        left = self.dfs(root.left, nodes)
        right = self.dfs(root.right, nodes)
        if left and right: # the lowest common ancestor
            return root
        return left or right
    
    def lowestCommonAncestor(self, root, nodes):
        
        """
        :type root: TreeNode
        :type nodes: List[TreeNode]
        """
        nodes = set(nodes)
        return self.dfs(root, nodes)
