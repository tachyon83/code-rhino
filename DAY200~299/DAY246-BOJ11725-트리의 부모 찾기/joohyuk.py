import sys
from collections import deque
si=sys.stdin.readline

n=int(si())
g,p=[[]for _ in range(n+1)],[0 for _ in range(n+1)]
for _ in range(n-1):
	a,b=[int(e) for e in si().split()]
	g[a].append(b)
	g[b].append(a)

q=deque()
q.append(1)
while q:
	curr=q.popleft()
	for nx in g[curr]:
		if nx!=p[curr]:
			p[nx]=curr
			q.append(nx)
for i in range(2,n+1):print(p[i])
