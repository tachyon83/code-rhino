triangle = [[-1],[2,3],[1,-1,-3]]

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        tmin = len(triangle)
        for i in range(1,tmin):
            triangle[i][0]+=triangle[i-1][0]
            triangle[i][-1]+=triangle[i-1][-1]
        for i in range(2,tmin):
            for j in range(1,i):
                triangle[i][j]+=min(triangle[i-1][j-1], triangle[i-1][j])
        print(triangle)
        return min(triangle[-1])


a = Solution()
a.minimumTotal(triangle)
