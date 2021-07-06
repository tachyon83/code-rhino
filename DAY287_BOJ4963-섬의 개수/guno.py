import sys
from collections import deque
input=sys.stdin.readline
sys.setrecursionlimit(10**6)
dx=[0,0,1,-1,1,1,-1,-1];dy=[1,-1,0,0,1,-1,1,-1]
_map,visited,x,y=[],[],0,0

def visit(j,i):
    for k in range(8):
        ny=j+dy[k];nx=i+dx[k]
        if 0<=ny<y and 0<=nx<x and not visited[ny][nx] and _map[ny][nx]==1:
            visited[ny][nx]=True
            visit(ny,nx)

while True:
    x,y=map(int,input().split())
    if x==0 or y==0:
        break
    _map=[list(map(int,input().split())) for _ in range(y)]
    visited=[[False]*x for _ in range(y)]
    cnt=0

    for j in range(y):
        for i in range(x):
            if _map[j][i]==1 and not visited[j][i]:
                visited[j][i]=True
                cnt+=1
                visit(j,i)
    print(cnt)
