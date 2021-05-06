import sys
from collections import deque
si=sys.stdin.readline

n=int(si())
names=[e for e in si().split()]
g,fam,ins=dict(),dict(),dict()
for name in names:
	g[name],fam[name],ins[name]=[],[],0
m=int(si())
while m:
	m-=1
	a,b=[e for e in si().split()]
	ins[a]+=1
	g[b].append(a)

q=deque()
for name in names:
	if not ins[name]:
		q.append(name)

print(len(q))
print(*sorted(q))
while q:
	curr=q.popleft()
	for nx in g[curr]:
		ins[nx]-=1
		if not ins[nx]:
			fam[curr].append(nx)
			q.append(nx)

names.sort()
for name in names:
	print(name,len(fam[name]),*sorted(fam[name]))
