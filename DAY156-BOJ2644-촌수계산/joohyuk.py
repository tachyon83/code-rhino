import sys
from collections import deque
si = sys.stdin.readline


def main():
    n = int(si())
    start, end = [int(e) for e in si().split()]
    m = int(si())
    graph = [set() for _ in range(n+1)]
    visited = [False for _ in range(n+1)]
    while m:
        m -= 1
        x, y = [int(e) for e in si().split()]
        graph[x].add(y)
        graph[y].add(x)

    visited[start] = True
    q, cnt, found = deque(), 0, False
    q.append(start)
    while q:
        cnt += 1
        qs = len(q)
        for _ in range(qs):
            curr = q.popleft()
            for e in graph[curr]:
                if e == end:
                    found = True
                    break
                if not visited[e]:
                    visited[e] = True
                    q.append(e)
        if found:
            break
    print(cnt if found else -1)

if __name__ == '__main__':
    main()
