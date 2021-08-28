import sys
sys.setrecursionlimit(int(1e5)+1)
si=sys.stdin.readline

n,r,q=[int(e) for e in si().split()]
g=[[]for _ in range(n+1)]
vis=[False for _ in range(n+1)]
pts=[0 for _ in range(n+1)]
for _ in range(n-1):
	u,v=[int(e) for e in si().split()]
	g[u].append(v)
	g[v].append(u)

def dfs(a):
	global g,vis
	s=0
	for nx in g[a]:
		if not vis[nx]:
			vis[nx]=True
			dfs(nx)
			s+=pts[nx]
	pts[a]=s+1
	
vis[r]=True
dfs(r)

while q:
	q-=1
	a=int(si())
	print(pts[a])
	
	
