import sys
from collections import deque
si=sys.stdin.readline
 
t=int(si())
while t:
	t-=1
	n,k=[int(e) for e in si().split()]
	g=[[]for _ in range(n+1)]
	ins=[0 for _ in range(n+1)]
	times=[int(e) for e in si().split()]
	ans=[0 for _ in range(n+1)]
	q=deque()
	while k:
		k-=1
		x,y=[int(e) for e in si().split()]
		g[x].append(y)
		ins[y]+=1
 
	for i in range(1,n+1):
		if not ins[i]:
			q.append(i)
 
	while q:
		curr=q.popleft()
		ans[curr]+=times[curr-1]
 
		for nx in g[curr]:
			ans[nx]=max(ans[nx],ans[curr])
			ins[nx]-=1
			if not ins[nx]:
				q.append(nx)
 
	goal=int(si())
	print(ans[goal])
