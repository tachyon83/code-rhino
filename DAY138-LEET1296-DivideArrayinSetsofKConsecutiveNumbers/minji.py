class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        nums.sort()
        while True:
            if len(nums) == 0:
                break
            a = nums[0]
            nums.remove(a)
            for i in range(1, k):
                b = a+i
                if b not in nums:
                    return False
                else:
                    nums.remove(b)
        return True
