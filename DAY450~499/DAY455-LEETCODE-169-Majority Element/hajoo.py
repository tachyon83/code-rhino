class Solution(object):
    def majorityElement(self, nums):
        cnt = 0
        element = 0
        
        for num in nums:
            if cnt == 0:
                element = num 
            if element == num:
                cnt += 1
            else:
                cnt -= 1
                
        return element
