class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dummy = [arr[:] for arr in triangle]
        for idx in range(1, len(triangle)):
            dummy[idx][0] = dummy[idx][0] + dummy[idx-1][0]
            dummy[idx][-1] = dummy[idx][-1] + dummy[idx-1][-1]
            for j in range(1,len(triangle[idx])-1):
                dummy[idx][j] = min(dummy[idx-1][j-1], dummy[idx-1][j]) + dummy[idx][j]
        return min(dummy[-1])
    
    
solution = Solution()
print(solution.minimumTital([[2],[3,4],[6,5,7],[4,1,8,3]]))


