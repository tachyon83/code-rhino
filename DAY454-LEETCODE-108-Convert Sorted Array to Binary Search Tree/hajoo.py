# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def sortedArrayToBST(self, nums):        
        def insertValue(node, l, r):
            if l > r:
                return
            
            mid = (l + r) // 2
            node = TreeNode(nums[mid])
            
            node.left = insertValue(node, l, mid - 1)
            node.right = insertValue(node, mid + 1, r)
            
            return node
            
        return insertValue(TreeNode(), 0, len(nums) - 1)

