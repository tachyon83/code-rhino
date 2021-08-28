import sys
from collections import deque
si=sys.stdin.readline

t=int(si())
while t:
	t-=1
	n,m=int(si()),int(si())
	g,vis=[set() for _ in range(1001)],[False for _ in range(1001)]
	par,root=[0 for _ in range(1001)],0
	nodes,flag=set(),False
	
	while m:
		m-=1
		a,b=[int(e) for e in si().split()]
		nodes.add(a)
		nodes.add(b)
		
		if not root:root=a
		
		if b in g[a]:
			flag=True
		g[a].add(b)
		if a in g[b]:
			flag=True
		g[b].add(a)
		
	q,vis[root]=deque(),True
	q.append(root)
	
	while q:
		curr=q.popleft()
		for nx in g[curr]:
			if nx==par[curr]:continue
			if vis[nx]:
				flag=True
				break
			vis[nx]=True
			par[nx]=curr
			q.append(nx)
		if flag:break
	
	for node in nodes:
		if not vis[node]:
			flag=True
			break
	if flag:print('graph')
	else:print('tree')
