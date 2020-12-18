import sys
from collections import deque

def bfs(v):
    cnt = 0
    q = deque([[v, cnt]])
    while q:
        v = q.popleft()
        e = v[0]
        cnt = v[1]
        if not visited[e]:
            visited[e] = True
            if e == k:
                return cnt
            cnt += 1
            if (e * 2) <= 100000:
                q.appendleft([e * 2, cnt-1])
            if (e + 1) <= 100000:
                q.append([e + 1, cnt])
            if (e - 1) >= 0:
                q.append([e - 1, cnt])
    return cnt

if __name__ == "__main__":
    n, k = list(map(int, sys.stdin.readline().split()))
    visited = [False] * 100001

    print(bfs(n))
