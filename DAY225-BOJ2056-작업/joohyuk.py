import sys
si=sys.stdin.readline

n=int(si())
t,ans=[0 for _ in range(n+1)],0
for j in range(n):
	line=[int(e) for e in si().split()]
	m=0
	for i in range(line[1]):
		m=max(m,t[line[i+2]])
	t[j+1]=line[0]+m
	ans=max(ans,t[j+1])
print(ans)
		
	
