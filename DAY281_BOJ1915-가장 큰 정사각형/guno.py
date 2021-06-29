import sys
input=sys.stdin.readline

n,m=map(int,input().split())
board=[list(input()) for _ in range(n)]
dp=[[0]*(m+1) for _ in range(n+1)]
answer=0
for i in range(n):
    for j in range(m):
        if board[i][j]=='1':
            dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
            answer=max(answer,dp[i][j])

print(answer**2)
