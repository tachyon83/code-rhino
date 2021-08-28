import sys
from collections import deque
si = sys.stdin.readline
sys.setrecursionlimit(int(1e5))

n, m = [int(e) for e in si().split()]
g, ginv = [[]for _ in range(n+1)], [[] for _ in range(n+1)]
vis, sccv = [False for _ in range(n+1)], [0 for _ in range(n+1)]
st, curr_sccv = deque(), 0
ng, w = [set() for _ in range(n+1)], [0 for _ in range(n+1)]

while m:
    m -= 1
    a, b = [int(e) for e in si().split()]
    if a == b:
        continue
    g[a].append(b)
    ginv[b].append(a)


def reset(n):
    global vis
    vis = [False for _ in range(n+1)]


def dfs1(a):
    global st
    for nx in g[a]:
        if not vis[nx]:
            vis[nx] = True
            dfs1(nx)
    st.append(a)


def dfs2(a, i):
    t = 1
    for nx in ginv[a]:
        if not vis[nx]:
            vis[nx] = True
            t += dfs2(nx, i)
    sccv[a] = i
    return t


for i in range(1, n+1):
    if not vis[i]:
        vis[i] = True
        dfs1(i)
reset(n)
while st:
    curr, flag = st.pop(), False
    if not vis[curr]:
        flag = True
        vis[curr] = True
        w[curr_sccv] = dfs2(curr, curr_sccv)
    if flag:
        curr_sccv += 1

inset, ins = [set() for _ in range(curr_sccv)], [0 for _ in range(curr_sccv)]
for i in range(1, n+1):
    for nx in g[i]:
        if sccv[i] == sccv[nx]:
            continue
        ng[sccv[i]].add(sccv[nx])
        inset[sccv[nx]].add(sccv[i])

q, wset = deque(), [set() for _ in range(curr_sccv)]

for i in range(curr_sccv):
    wset[i].add(i)
    ins[i] = len(inset[i])
    if not ins[i]:
        q.append(i)
while q:
    curr = q.popleft()
    for nx in ng[curr]:
        ins[nx] -= 1
        wset[nx] |= wset[curr]
        if not ins[nx]:
            q.append(nx)

scct = [sum(w[j] for j in wset[i]) for i in range(curr_sccv)]
mx = max(scct)
for i in range(1, n+1):
    if scct[sccv[i]] == mx:
        print(i, end=' ')
