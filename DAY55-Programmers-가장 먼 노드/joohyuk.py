from collections import deque

def solution(n, edge):
    vis,graph,cost=[False for _ in range(n+1)],[[]for _ in range(n+1)],[0 for _ in range(n+1)]
    for e in edge:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    
    vis[1],q,d=True,deque(),0
    q.append(1)
    while q:
        d+=1
        qs=len(q)
        for _ in range(qs):
            curr=q.popleft()
            for nx in graph[curr]:
                if not vis[nx]:
                    q.append(nx)
                    cost[nx]=d
                    vis[nx]=True
    mx,answer=max(cost),0
    for i in range(1,n+1):
        if cost[i]==mx:answer+=1
    
    return answer
