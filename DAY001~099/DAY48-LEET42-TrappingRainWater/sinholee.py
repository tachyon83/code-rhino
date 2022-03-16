class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        h_len = len(height)
        top_idx = 0
        top = 0
        for i in range(h_len):
            if top < height[i]:
                top = height[i]
                top_idx = i
        total = 0
        curr = 0
        for i in range(top_idx):
            if curr <height[i]:
                curr = height[i]
            else:
                total += curr-height[i]
        curr = 0
        for i in range(h_len-1, top_idx, -1):
            if curr < height[i]:
                curr = height[i]
            else:
                total += curr-height[i]
        return total        
        
        
        
