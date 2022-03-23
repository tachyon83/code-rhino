# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator(object):

    def __init__(self, root):
        self.nodes = []
        self.now = 0
        self.inorder(root)
        
    def inorder(self, node):
        if node.left != None:
            self.inorder(node.left)
        self.nodes.append(node.val)
        if node.right != None:
            self.inorder(node.right)

    def next(self):
        self.now += 1
        return self.nodes[self.now - 1]       

    def hasNext(self):
        if self.now < len(self.nodes):
            return 1
        else:
            return 0
