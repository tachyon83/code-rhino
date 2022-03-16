# DP 문제

import sys

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        length_nums = len(nums)
        # dp[i] : i번째 원소를 마지막 원소로 가지는 부분열의 연속합
        dp = [-sys.maxsize for _ in range(length_nums)]
        dp[0] = nums[0]
        # 연속합은 중간에 끊기지 않으므로, dp[i]는 dp[i-1] + i번째 원소, i번째 원소 둘 중 큰 것
        for i in range(1, length_nums):
            dp[i] = max(dp[i-1]+nums[i], nums[i])
        return max(dp)
