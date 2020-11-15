class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        length = len(nums)
        if length:
            for i in range(length):
                while nums[i] > 0 and nums[i] < length and nums[nums[i]-1] != nums[i]:
                    nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
            for i in range(length):
                if nums[i] != i+1:
                    return i+1
            else:
                return length +1
        else:
            return 1
