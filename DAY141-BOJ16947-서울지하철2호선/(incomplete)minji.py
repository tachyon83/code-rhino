import sys
from collections import deque
sys.setrecursionlimit(10**9)

def dfs(cur, pre):
    if ch[cur] == 1:
        return cur
    ch[cur] = 1

    for i in maps[cur]:
        if i == pre:
            continue
        if (res := dfs(i, cur)) >= 0:
            ch[cur] = 2
            return res if cur != res else -1

def bfs():
    q = deque([])

    for i in range(n):
        if ch[i] == 2:
            q.append(i)
        else:
            dis[i] = -1

    while q:
        tmp = []
        for cur in q:
            for j in maps[cur]:
                if dis[j] != -1:
                    continue
                dis[j] = dis[cur] + 1
                tmp.append(j)
        q = tmp

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    ch = [0] * n
    dis = [0] * n
    maps = [[] for _ in range(n)]

    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        maps[a-1].append(b-1)
        maps[b-1].append(a-1)

    dfs(0, -1)
    bfs()
    print(*dis)
