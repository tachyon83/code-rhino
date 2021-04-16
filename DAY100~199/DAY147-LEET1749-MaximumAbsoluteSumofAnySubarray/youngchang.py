class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        acc = nums.copy()
        for i in range(1, len(acc)):
            acc[i] = max(acc[i], acc[i - 1] + acc[i])
        cand1 = max(acc)
        
        acc = [-i for i in nums]
        for i in range(1, len(acc)):
            acc[i] = max(acc[i], acc[i - 1] + acc[i])
        cand2 = max(acc)
        
        return max(cand1, cand2)