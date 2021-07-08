import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
_map=[list(input()) for _ in range(n)]
dx,dy=[0,0,1,-1],[1,-1,0,0]
INF=10**8
dp0,dp1=[[INF]*m for _ in range(n)],[[INF]*m for _ in range(n)]
q=deque()
q.append((0,0,1,False))
dp0[0][0]=1
while q:
    x,y,cnt,isBreak=q.popleft()
    for i in range(4):
        nx,ny=x+dx[i],y+dy[i]
        if 0<=nx<n and 0<=ny<m:
            if _map[nx][ny]=='1':
                if not isBreak and cnt+1<dp1[nx][ny]:
                    dp1[nx][ny]=cnt+1
                    q.append((nx,ny,cnt+1,True))
            else:
                if not isBreak:
                    if cnt+1<dp0[nx][ny]:
                        dp0[nx][ny]=cnt+1
                        q.append((nx,ny,cnt+1,False))
                else:
                    if cnt+1<dp1[nx][ny]:
                        dp1[nx][ny]=cnt+1
                        q.append((nx,ny,cnt+1,True))
                

answer=min(dp0[-1][-1],dp1[-1][-1])
print(answer if answer!=INF else -1)
