class Solution(object):
    def isMatch(self, s, p):
        dp = [[False for _ in range(len(s)+1)] for _ in range(len(p)+1)]
        dp[0][0] = True

        for i in range(1, len(p)+1):
            if dp[i-2][0] and p[i-1] == '*':
                dp[i][0] = True
                
        for i in range(1, len(p)+1):
            for j in range(1, len(s)+1):
                if p[i-1] == s[j-1] or p[i-1] == '.':
                    dp[i][j] = dp[i-1][j-1]
                elif p[i-1] == '*':
                    if s[j-1] == p[i-2] or p[i-2] == '.':
                        dp[i][j] = dp[i][j-1] or dp[i-1][j] or dp[i-2][j]
                    else:
                        dp[i][j] = dp[i-1][j] or dp[i-2][j]
        return dp[-1][-1]
