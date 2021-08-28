import sys
from collections import deque
sys.setrecursionlimit(int(1e4)+1)
si=sys.stdin.readline

n,m=[int(e) for e in si().split()]
vis,scc,allScc=[False for _ in range(n+1)],[],[]
st,g,ig=deque(),[[]for _ in range(n+1)],[[]for _ in range(n+1)]
while m:
	m-=1
	a,b=[int(e) for e in si().split()]
	g[a].append(b)
	ig[b].append(a)

def dfs1(a):
	global st,g,vis
	vis[a]=True
	for nx in g[a]:
		if not vis[nx]:
			dfs1(nx)
	st.append(a)
	
def dfs2(a):
	global st,ig,vis,scc
	vis[a]=True
	scc.append(a)
	for nx in ig[a]:
		if not vis[nx]:
			dfs2(nx)
	

for i in range(1,n+1):
	if not vis[i]:dfs1(i)
vis=[False for _ in range(n+1)]
while st:
	curr=st.pop()
	if not vis[curr]:
		dfs2(curr)
		scc.sort()
		allScc.append(scc)
		scc=[]

allScc.sort()
print(len(allScc))
for el in allScc:
	print(*el,end=' ')
	print(-1)
