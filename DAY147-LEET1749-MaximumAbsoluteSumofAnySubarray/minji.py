"""
Kadane's algorithm
"""

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        res, pos, neg = 0, 0, 0
        for num in nums:
            pos = max(0, pos + num)
            neg = min(0, neg + num)
            res = max(res, pos, -neg)
        return res
