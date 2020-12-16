class Solution:
    def firstMissingPositive(self, nums):
                
        if len(nums) == 0 or 1 not in nums:
            return 1
        
        nums.sort()
        s_num = 0

        for i in range(len(nums) - 1):
            if nums[i] <= 0 or nums[i] == nums[i + 1]:
                continue
            else:
                if nums[i + 1] - nums[i] != 1:
                    s_num = nums[i] + 1
                    return s_num    
        if s_num == 0:
            s_num = nums[-1] + 1
        return s_num
