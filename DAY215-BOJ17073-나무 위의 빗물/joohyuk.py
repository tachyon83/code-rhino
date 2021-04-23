import sys
sys.setrecursionlimit(int(5e5)+1)
si=sys.stdin.readline
n,w=[int(e) for e in si().split()]
g,cnt,vis=[[]for _ in range(n+1)],0,[False for _ in range(n+1)]
for _ in range(n-1):
	u,v=[int(e) for e in si().split()]
	g[u].append(v)
	g[v].append(u)

def dfs(a):
	global g,vis,cnt
	vis[a],flag=True,False
	for nx in g[a]:
		if not vis[nx]:
			flag=True
			dfs(nx)
	if not flag:
		cnt+=1
	
dfs(1)
print(w/cnt)
	
