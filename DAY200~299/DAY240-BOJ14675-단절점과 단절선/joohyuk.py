import sys
si=sys.stdin.readline
n=int(si())
g=[[]for _ in range(n+1)]
for _ in range(n-1):
	a,b=[int(e) for e in si().split()]
	g[a].append(b)
	g[b].append(a)

q=int(si())
while q:
	q-=1
	t,k=[int(e) for e in si().split()]
	if t==2:print('yes')
	else:
		if len(g[k])==1:print('no')
		else:print('yes')
