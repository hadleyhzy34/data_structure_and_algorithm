class Solution:
    # @staticmethod
    def printInorder(self, node, res):
        if node == None:
            return
        self.printInorder(node.left, res)
        res.append(node.val)
        self.printInorder(node.right, res)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        self.printInorder(root, res)
        return res

    class Solution:
    @staticmethod
    def printInorder(node, res):
        if node == None:
            return
        Solution.printInorder(node.left, res)
        res.append(node.val)
        Solution.printInorder(node.right, res)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        Solution.printInorder(root, res)
        return res
