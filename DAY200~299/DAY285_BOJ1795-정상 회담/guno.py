import sys
from collections import deque
input=sys.stdin.readline

n,m=map(int,input().split())
board=[input() for _ in range(n)]
INF=10**8
maal=[]
for i in range(n):
    for j in range(m):
        a=board[i][j]
        if '1'<=a<='9':
            maal.append((int(a),i,j))
move=[(1,2),(-1,2),(1,-2),(-1,-2),(2,1),(-2,1),(2,-1),(-2,-1)]
dps=[]
for kind,x1,y1 in maal:
    temp=[[INF]*m for _ in range(n)]
    temp[x1][y1]=0
    q=deque()
    q.append((x1,y1,0))
    while q:
        x,y,cnt=q.popleft()
        for dx,dy in move:
            nx=x+dx;ny=y+dy
            if 0<=nx<n and 0<=ny<m and temp[nx][ny]>cnt+1:
                temp[nx][ny]=cnt+1
                q.append((nx,ny,cnt+1))
    for i in range(n):
        for j in range(m):
            if temp[i][j]!=INF:
                temp[i][j]=(temp[i][j]-1)//kind+1
    dps.append(temp)

dp=[[INF]*m for _ in range(n)]
for i in range(n):
    for j in range(m):
        dp[i][j]=sum([dps[k][i][j] for k in range(len(dps))])
answer=min(min(x) for x in dp)
if answer>=INF:
    print(-1)
else:
    print(answer)
