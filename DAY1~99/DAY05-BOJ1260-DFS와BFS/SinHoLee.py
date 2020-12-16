from collections import deque
import sys


# 재귀버전
def dfs_rec(v, res, visited):
    if visited[v]:
        return []
    visited[v] = 1
    res.append(v)
    for v in graph[v]:
        # res와 visited를 글로벌에서 선언한다면, for문 안에 방문처리 할 필요없음
        if visited[v]:
            continue
        dfs_rec(v, res, visited)
    return res


# 스택버전
def dfs(v):
    stack = [v]
    visited = [0] * (N+1)
    s = []
    while stack:
        node = stack.pop()
        # 방문체크를 pop하고 바로 해야한다.
        if visited[node]:
            continue
        s.append(node)
        visited[node] = 1
        for v in graph[node][::-1]:
            stack.append(v)
    return " ".join(map(str, s))


# 큐버전
def bfs(v):
    queue = deque([v])
    visited = [0] * (N+1)
    visited[v] = 1
    s = [v]
    while queue:
        # 순서에 대한 제약이 없다면, popleft를 pop()으로 바꾸면 dfs가 된다.
        node = queue.popleft()
        for v in graph[node]:
            if visited[v]:
                continue
            visited[v] = 1
            s.append(v)
            queue.append(v)
    return " ".join(map(str, s))


N, M, V = map(int, sys.stdin.readline().strip().split())
graph = [[] for _ in range(N+1)]
for i in range(M):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

for g in graph:
    g.sort()

# print(" ".join(map(str, dfs_rec(V, [], [0] * (N+1)))))
print(dfs(V))
print(bfs(V))

