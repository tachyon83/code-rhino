from collections import deque

def solution(isConnected):
    n=len(isConnected)
    g,vis=[[]for _ in range(n)],[False for _ in range(n)]

    for i in range(n):
        for j in range(i+1,n):
            if isConnected[i][j]:
                g[i].append(j)
                g[j].append(i)
    
    def dfs(a):
        nonlocal g,vis,n
        for nx in g[a]:
            if not vis[nx]:
                vis[nx]=True
                dfs(nx)

    t=0
    for e in range(n):
        if not vis[e]:
            t+=1
            vis[e]=True
            dfs(e)
    return t
