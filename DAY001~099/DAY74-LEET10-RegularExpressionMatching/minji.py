class Solution:
    def isMatch(self, s, p):
        n = len(s)
        m = len(p)

        maps = [[False for _ in range(m+1)] for _ in range(n+1)]
        maps[0][0] = True
        for j in range(2, m+1):
            if p[j-1] == "*":
                maps[0][j] = maps[0][j-2]

        for i in range(1, n+1):
            for j in range(1, m+1):
                if p[j-1] == ".":
                    maps[i][j] = maps[i-1][j-1]
                elif p[j-1] == "*":
                    if maps[i][j-2] or maps[i][j-1] or ((p[j-2] == "." or p[j-2] == s[i-1]) and maps[i-1][j]):
                        maps[i][j] = True
                else:
                    maps[i][j] = maps[i-1][j-1] and p[j-1] == s[i-1]
        return maps[n][m]
