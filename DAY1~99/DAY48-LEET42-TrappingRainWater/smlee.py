class Solution:
    def trap(self, height) :
        i = 0 
        j = len(height)-1
        imax = 0
        jmax = 0
        water = 0
        while i < j:
            if height[i] < height[j]:
                imax = max(imax, height[i])
                water += (imax - height[i])
                i += 1
            else:
                jmax = max(jmax, height[j])
                water += (jmax - height[j])
                j -= 1
        return water
