import sys

def solve(now, end, remain, pay):
    global total
    visit[now] = True
    if now == end:
        total = min(total, pay)
        return
    for (v, money) in g[now]:
        if not visit[v] and money <= remain:
            visit[v] = True
            solve(v, end, remain - money, max(pay, money))
            visit[v] = False


n, m, s, e, c = map(int, sys.stdin.readline().split())
g = [[] for _ in range(n+1)]
visit = [False for _ in range(n+1)]
total = sys.maxsize
for _ in range(m):
    v1, v2, cost = map(int, sys.stdin.readline().split())
    g[v1].append((v2, cost))
    g[v2].append((v1, cost))

solve(s, e, c, 0)
if total == sys.maxsize:
    total = -1
print(total)
