import sys
si=sys.stdin.readline

n=int(si())
nums=[int(e) for e in si().split()]
dp=[[0 for _ in range(20+1)]for _ in range(n)]
dp[0][nums[0]]=1
for i in range(1,n):
    if i==n-1:
        dp[i][nums[-1]]=dp[i-1][nums[-1]]
        continue
    for j in range(20+1):
        if not dp[i-1][j]:continue
        v=j+nums[i]
        if 0<=v<=20:dp[i][v]+=dp[i-1][j]
        v=j-nums[i]
        if 0<=v<=20:dp[i][v]+=dp[i-1][j]

print(dp[n-1][nums[-1]])
