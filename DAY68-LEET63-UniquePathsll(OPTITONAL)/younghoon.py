class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid)
        m = len(obstacleGrid[0])
        
        for i in range(n):
            for j in range(m):
                if obstacleGrid[i][j] == 1:
                    obstacleGrid[i][j] = "obs"
                    
        
        for i in range(n):
            if obstacleGrid[i][0] != "obs":
                obstacleGrid[i][0] = 1
            else:
                break
        for i in range(m):
            if obstacleGrid[0][i] != "obs":
                obstacleGrid[0][i] = 1
            else:
                break
                
        for i in range(1,n):
            for j in range(1,m):
                if obstacleGrid[i][j] == "obs":
                    continue
                if obstacleGrid[i][j-1] == "obs":
                    obstacleGrid[i][j] = obstacleGrid[i-1][j]
                    continue
                if obstacleGrid[i-1][j] == "obs":
                    obstacleGrid[i][j] = obstacleGrid[i][j-1]
                    continue
                obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j]
        if obstacleGrid[n-1][m-1] == "obs" or obstacleGrid[0][0] == "obs":
            return 0
        return obstacleGrid[n-1][m-1]
                    
                    
        
