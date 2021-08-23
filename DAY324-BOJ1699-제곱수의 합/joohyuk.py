import sys
from math import sqrt
si = sys.stdin.readline

n, big = int(si()), int(1e5)+1
dp = [big for _ in range(n+1)]
dp[0] = 0

for i in range(n):
    for j in range(1, int(sqrt(n))+1):
        v = i+j*j
        if v <= n:
            dp[v] = min(dp[v], dp[i]+1)
        else:
            break
print(dp[n])
