import sys
si=sys.stdin.readline

n=int(si())
dp,board=[[0 for _ in range(n)]for _ in range(n)],[]
dp[0][0]=1

for _ in range(n):board.append([int(e) for e in si().split()])
for i in range(n):
    for j in range(n):
        if i==n-1 and j==n-1:continue
        curr=board[i][j]
        ni,nj=i+curr,j+curr
        if ni<n:dp[ni][j] += dp[i][j]
        if nj<n:dp[i][nj] += dp[i][j]
print(dp[n-1][n-1])
