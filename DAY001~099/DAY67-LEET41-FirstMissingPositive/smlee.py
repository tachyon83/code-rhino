class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        num = 1
        
        if 1 not in nums :
            return 1
        
        nums.sort()
        
        for i in nums :
            if i <= 0 :
                pass
            elif i == num :
                num += 1
        return num
