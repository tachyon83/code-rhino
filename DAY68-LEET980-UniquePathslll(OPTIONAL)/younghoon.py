class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        start = None
        end = None
        empty = 0
        self.result = 0
        row = len(grid)
        col = len(grid[0])
        #east west south north         
        dirx = [0,0,1,-1]
        diry = [1,-1,0,0]
        visited = set()
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    start = (i,j)
                if grid[i][j] == 2:
                    end = (i,j)
                if grid[i][j] == 0:
                    empty += 1
        
        def backtracking(curr, walk, visited):
            if curr == end:
                if walk == empty + 1:
                    self.result += 1
                return
            if 0<=curr[0]<row and 0<=curr[1]<col and grid[curr[0]][curr[1]] != -1 and curr not in visited:
                visited.add(curr)
                for i in range(4):
                    nxt = (curr[0] + dirx[i], curr[1] + diry[i])
                    backtracking(nxt, walk + 1, visited)
                visited.remove(curr)
        backtracking(start, 0, visited)
        return self.result
