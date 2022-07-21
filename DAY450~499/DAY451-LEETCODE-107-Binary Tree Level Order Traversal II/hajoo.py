# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def levelOrderBottom(self, root):
        if not root:
            return
        ans = []
        q = [root]
        while q:
            tmp = []
            vals = []
            for node in q:
                if node:
                    vals.append(node.val)
                    tmp.append(node.left)
                    tmp.append(node.right)
            
            if vals:
                ans.append(vals)
                vals = []
            q = tmp[:]
        
        return ans[::-1]
