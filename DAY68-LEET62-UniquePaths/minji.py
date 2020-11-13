class Solution:
    def uniquePaths(self, m, n) -> int:
        return int(self.factorial(m+n-2) / (self.factorial(m-1) * self.factorial(n-1)))
    
    def factorial(self, n):
        num = 1
        while n >= 1:
            num = num * n
            n = n - 1
        return num
