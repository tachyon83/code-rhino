import sys
si=sys.stdin.readline

n,k=[int(e) for e in si().split()]
hist=[[0 for _ in range(n+1)]for _ in range(n+1)]
while k:
	k-=1
	a,b=[int(e) for e in si().split()]
	hist[a][b]=-1
	hist[b][a]=1

for k in range(1,n+1):
	for i in range(1,n+1):
		for j in range(1,n+1):
			if not hist[i][k] or not hist[k][j]:continue
			if hist[i][k]+hist[k][j]>0:hist[i][j]=1
			elif hist[i][k]+hist[k][j]<0:hist[i][j]=-1

s=int(si())
while s:
	s-=1
	a,b=[int(e) for e in si().split()]
	print(hist[a][b])
	
	
