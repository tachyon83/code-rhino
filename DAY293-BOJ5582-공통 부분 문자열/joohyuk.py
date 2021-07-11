import sys
si = sys.stdin.readline

s = si()[:-1]
t = si()[:-1]
ssz, tsz, mx = len(s), len(t), 0
dp = [[0 for _ in range(tsz)]for _ in range(ssz)]

for i in range(ssz):
    for j in range(tsz):
        if s[i] == t[j]:
            if not i or not j:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j-1]+1
            mx = max(mx, dp[i][j])
print(mx)
