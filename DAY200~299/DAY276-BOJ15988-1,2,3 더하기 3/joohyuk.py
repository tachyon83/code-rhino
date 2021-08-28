import sys
si = sys.stdin.readline

t, mod, sz = int(si()), int(1e9)+9, int(1e6)+1
dp = [0 for _ in range(sz)]
dp[1], dp[2], dp[3] = 1, 2, 4
for i in range(4, sz):dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]) % mod
while t:
    t -= 1
    n = int(si())
    print(dp[n])
