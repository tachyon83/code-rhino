from collections import defaultdict

class Solution:
    def trap(self, height: List[int]) -> int:
        result=[]
        l, r = 0, len(height)-1
        l_max, r_max = 0, 0 
        while l<r:
            if height[l]<height[r]:
                if height[l]>l_max:
                    l_max=height[l]
                else: result.append(l_max-height[l])
                l+=1
            else:
                if height[r]>r_max:
                    r_max=height[r]
                else: result.append(r_max-height[r])
                r-=1
        return (sum(result))
