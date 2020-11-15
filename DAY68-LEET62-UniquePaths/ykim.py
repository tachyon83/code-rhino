class Solution(object):
    def helper(self, i, j, m, n, paths):
        if 0<=i<m and 0<=j<n:
            if paths[i][j] != -1:
                return paths[i][j]
            paths[i][j] = self.helper(i, j+1, m, n, paths) + self.helper(i+1, j, m, n, paths)
            return paths[i][j]
        return 0
    
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m == 0 or n == 0:
            return 0
        paths = [[-1]*n for _ in range(m)]
        paths[m-1][n-1] = 1
        return self.helper(0, 0, m, n, paths)
