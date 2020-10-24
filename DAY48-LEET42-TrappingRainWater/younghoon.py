class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        volume = 0
        left, right = 0, len(height)-1
        max_left, max_right = height[left], height[right]
        
        while left < right:
            max_left = max(height[left], max_left)
            max_right = max(height[right], max_right)
            
            if max_left <= max_right:
                volume += max_left - height[left]
                left += 1
            else:
                volume += max_right - height[right]
                right -= 1
        return volume
                
            
        
        
