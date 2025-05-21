class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def deleteNode(self, root, key): 
        if not root:
            return None 
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.left:
                return root.right
            elif not root.right: 
                return root.left

            min_larger_node = self.getMin(root.right)
            root.val = min_larger_node.val
            root.right = self.deleteNode(root.right, root.val)
        return root

    def getMin(self, node):
        while node.left:
            node = node.left
        return node
