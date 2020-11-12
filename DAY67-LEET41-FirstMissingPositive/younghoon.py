class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        if not nums:
            return 1
        i = 1
        while True:
            if i not in nums:
                return i
            i+=1
