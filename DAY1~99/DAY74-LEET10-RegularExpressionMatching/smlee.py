class Solution(object):
    def isMatch(self, s, p):
        m,n = len(s),len(p)
        dp = [[False for j in range(n+1)] for i in range(m+1)]
        dp[0][0] = True
        
        for i in range(m+1):
            for j in range(1,n+1):
                if p[j-1]=="*":
                    dp[i][j] = dp[i][j-2] or i>0 and dp[i-1][j] and (s[i-1]==p[j-2] or p[j-2]==".")
                else:
                    dp[i][j] = i>0 and dp[i-1][j-1] and (s[i-1]==p[j-1] or p[j-1]==".")
        
        return dp[-1][-1]
