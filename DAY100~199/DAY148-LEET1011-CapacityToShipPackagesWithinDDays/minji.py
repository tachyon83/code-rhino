
class Solution:
    def getday(self, weights, m):
        subsum, day = 0, 1
        for i in range(len(weights)):
            cur_w = weights[i]
            nextsubsum = subsum + cur_w
            if (m < nextsubsum):
                day +=1
                subsum = cur_w
        
            else: 
                subsum = nextsubsum
        
        return day
    
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        l, r = max(weights), sum(weights)
        while l < r:
            m = (l + r) // 2
            if (self.getday(weights, m) <= D): 
                r = m
            else: 
                l = m + 1
        
        return r
