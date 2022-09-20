// Date: September 20, 2022
preIndex, posIndex = 0, 0
    def constructFromPrePost(self, pre, post):
        root = TreeNode(pre[self.preIndex])
        self.preIndex += 1
        if (root.val != post[self.posIndex]):
            root.left = self.constructFromPrePost(pre, post)
        if (root.val != post[self.posIndex]):
            root.right = self.constructFromPrePost(pre, post)
        self.posIndex += 1
        return root
