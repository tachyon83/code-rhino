class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        cur = 1
        for n in sorted(set(nums)):
            if n <= 0:
                continue
            elif n != cur:
                break
            cur += 1
        return cur
