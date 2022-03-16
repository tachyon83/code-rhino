class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        paths = [[0]*m for _ in range(n)]
        paths[0][0] = 1
        for i in range(n):
            for j in range(m):
                if i==0 and j ==0 :
                    pass
                if i > 0 :
                    paths[i][j] += paths[i-1][j]                    
                if j > 0 :
                    paths[i][j] += paths[i][j-1]      
        return paths[i][j]
