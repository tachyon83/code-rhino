class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        grid = [[0] * n for _ in range(m)]
        for i in range(m):
            grid[i][0] = 1
        for j in range(n):
            grid[0][j] = 1
        for x in range(1,m):
            for y in range(1,n):
                grid[x][y] = grid[x-1][y] + grid[x][y-1]
        return grid[m-1][n-1]
        
            
