import sys
from collections import deque
si = sys.stdin.readline

vis, g = [], []


def bfs(i):
    global vis, g
    q = deque()
    q.append(i)

    while q:
        curr = q.popleft()
        for j, v in enumerate(g[curr]):
            if j != curr and not vis[j] and v:
                vis[j] = True
                q.append(j)


def solution(n, computers):
    global vis, g
    g = computers
    vis, answer = [False for _ in range(n)], 0

    for i in range(n):
        if not vis[i]:
            answer += 1
            vis[i] = True
            bfs(i)

    return answer
