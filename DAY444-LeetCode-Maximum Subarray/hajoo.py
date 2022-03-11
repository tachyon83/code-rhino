class Solution(object):
    def maxSubArray(self, nums):
        idx, sumVal = 0, 0
        ans = -float('INF')
        while idx < len(nums):
            sumVal += nums[idx]
            ans = max(ans, sumVal)
            if sumVal < 0:
                sumVal = 0
            idx += 1
        return ans
