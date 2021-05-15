import sys
si=sys.stdin.readline
sys.setrecursionlimit(int(1e6)+1)

n=int(si())
mn=n
vis,adp=[False for _ in range(n+1)],[[-1,-1] for _ in range(n+1)]
g=[[]for _ in range(n+1)]
for _ in range(n-1):
	a,b=[int(e) for e in si().split()]
	g[a].append(b)
	g[b].append(a)

def propagate(a,v,p):
	if adp[a][v]!=-1:return adp[a][v]
	s=0
	for nx in g[a]:
		if nx==p:continue
		s+=propagate(nx,0,a)
	adp[a][1]=s+1
	if v:return adp[a][1]
	s=0
	for nx in g[a]:
		if nx==p:continue
		s+=propagate(nx,1,a)
	adp[a][0]=min(adp[a][1],s)
	return adp[a][0]

print(min(propagate(1,0,0),propagate(1,1,0)))
