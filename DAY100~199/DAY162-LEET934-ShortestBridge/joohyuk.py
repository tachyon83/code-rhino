import sys
sys.setrecursionlimit(10000+1)
from collections import deque

def solution(A):
    n=len(A)
    vis=[[0 for _ in range(n)]for _ in range(n)]
    island,sz=0,[0,0]
    dr,dc=[0,1,0,-1],[1,0,-1,0]

    def dfs(i,j):
        nonlocal dr,dc,vis,A,sz,lsland,n
        for idx in range(4):
            ni,nj=i+dr[idx],j+dc[idx]
            if 0<=ni<n and 0<=nj<n and A[ni][nj] and not vis[ni][nj]:
                vis[ni][nj]=island
                sz[island-1]+=1
                dfs(ni,nj)


    for i in range(n):
        for j in range(n):
            if A[i][j]:
                if not vis[i][j]:
                    island+=1
                    vis[i][j]=1
                    sz[island-1]+=1
                    dfs(i,j)
    
    choice=2
    if sz[0]<sz[1]:
        choice=1
    
    mn=10000+5
    for i in range(n):
        for j in range(n):
            if vis[i][j]==choice:
                visited=[[False for _ in range(n)]for _ in range(n)]
                q,t,flag=deque(),-1,False

                q.append([i,j])
                visited[i][j]=True
                while q:
                    qs=len(q)
                    t+=1
                    for _ in range(qs):
                        cr,cc=q.popleft()
                        for idx in range(4):
                            nr,nc=cr+dr[idx],cc+dc[idx]
                            if 0<=nr<n and 0<=nc<n:
                                if not vis[nr][nc] and not visited[nr][nc]:
                                    visited[nr][nc]=True
                                    q.append([nr,nc])
                                elif vis[nr][nc]!=choice:
                                    flag=True
                                    break
                        if flag:break
                    if flag:break
                mn=min(mn,t)
    return mn
