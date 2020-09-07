import sys
from collections import deque
si = sys.stdin.readline
graph_unsorted = [set() for _ in range(1001)]
graph = [[]for _ in range(1001)]
visited = [False for _ in range(1001)]


def dfs(s):
    print(s, end=' ')
    for e in graph[s]:
        if not visited[e]:
            visited[e] = True
            dfs(e)


def main():
    n, m, v = [int(e) for e in si().split()]
    while m:
        m -= 1
        a, b = [int(e) for e in si().split()]
        graph_unsorted[a].add(b)
        graph_unsorted[b].add(a)

    for i in range(1, n+1):
        e = list(graph_unsorted[i])
        e.sort()
        graph[i] = e

    visited[v] = True
    dfs(v)
    print()

    q = deque()
    for i in range(1, n+1):
        visited[i] = False
    q.append(v)
    visited[v] = True
    while q:
        curr = q.popleft()
        print(curr, end=' ')
        for e in graph[curr]:
            if not visited[e]:
                visited[e] = True
                q.append(e)
    print()


if __name__ == '__main__':
    main()
