from collections import deque

def bfs(v, visited, adj):
    cnt = 0
    q = deque([[v, cnt]])
    while q:
        value = q.popleft()
        v = value[0]
        cnt = value[1]
        if visited[v] == -1:
            visited[v] = cnt
            cnt += 1
            for e in adj[v]:
                q.append([e, cnt])

def solution(n, edge):
    answer = 0
    visited = [-1] * (n + 1)
    adj = [[] for _ in range(n + 1)]
    for e in edge:
        x = e[0]
        y = e[1]
        adj[x].append(y)
        adj[y].append(x)
    bfs(1, visited, adj)
    for value in visited:
        if value == max(visited):
            answer += 1
    return answer
