import sys
input=sys.stdin.readline
sys.setrecursionlimit(999999)

n,m=map(int,input().split())
board=[list(map(int,input().split())) for i in range(n)]
dp=[[-1]*m for _ in range(n)]

dx=[0,0,1,-1]
dy=[1,-1,0,0]

def dfs(x,y):
    if x==0 and y==0:
        return 1
    if dp[x][y]!=-1:
        return dp[x][y]
    dp[x][y]=0
    for i in range(4):
        nx,ny=x+dx[i],y+dy[i]
        if 0<=nx<n and 0<=ny<m and board[nx][ny]>board[x][y]:
            dp[x][y]+=dfs(nx,ny)
    return dp[x][y]

print(dfs(n-1,m-1))
