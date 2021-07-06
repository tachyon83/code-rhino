import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
MAP= [list(map(int,input().split())) for _ in range(n)]
dists=[[0]*n for _ in range(n)]

islands=[]
dx=[0,0,1,-1];dy=[1,-1,0,0]
_cnt=2

for i in range(n):
    for j in range(n):
        if MAP[i][j]==1:
            q=deque()
            q.append((i,j))
            MAP[i][j]=_cnt
            islands.append((i,j,_cnt))

            while q:
                x,y=q.popleft()
                for k in range(4):
                    nx=x+dx[k];ny=y+dy[k]
                    if 0<=ny<n and 0<=nx<n and MAP[nx][ny]==1:
                        MAP[nx][ny]=_cnt
                        islands.append((nx,ny,_cnt))
                        q.append((nx,ny))
            _cnt+=1

for nx,ny,cnt in islands:
    MAP[nx][ny]=cnt

answer,dist=100000,1
while islands:
    q=[]
    for x,y,cnt in islands:
        for k in range(4):
            nx=x+dx[k];ny=y+dy[k]
            if 0<=ny<n and 0<=nx<n:
                if 0!=MAP[nx][ny]!=cnt:
                    answer=min(answer,dist+dists[nx][ny]-1)
                if 0==MAP[nx][ny]:
                    MAP[nx][ny]=cnt
                    dists[nx][ny]=dist
                    q.append((nx,ny,cnt))
    islands=q
    dist+=1
print(answer)
