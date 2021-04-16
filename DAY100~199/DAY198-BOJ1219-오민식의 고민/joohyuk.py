import sys
import math
si = sys.stdin.readline

n, s, e, m = [int(e) for e in si().split()]
money = [-math.inf for _ in range(n)]
g, ig = [[]for _ in range(n)], [[]for _ in range(n)]
while m:
    m -= 1
    a, b, c = [int(e) for e in si().split()]
    g[a].append([b, c])
    ig[b].append([a, c])
earning = [int(e) for e in si().split()]
money[s] = earning[s]

vis = [False for _ in range(n)]
reachables = set()


def dfs(a):
    global vis, ig, reachables
    reachables.add(a)
    for np in ig[a]:
        if not vis[np[0]]:
            vis[np[0]] = True
            dfs(np[0])


dfs(e)
flag = False
for i in range(n):
    for city in range(n):
        for np in g[city]:
            if money[city] != -math.inf and money[np[0]] < money[city]+earning[np[0]]-np[1]:
                money[np[0]] = money[city]+earning[np[0]]-np[1]
                if i == n-1:
                    if np[0] in reachables:
                        flag = True

if money[e] == -math.inf:
    print('gg')
elif flag:
    print('Gee')
else:
    print(money[e])
