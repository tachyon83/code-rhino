import sys,heapq
si=sys.stdin.readline
 
n,m=[int(e) for e in si().split()]
s,e=[int(e) for e in si().split()]

g,cost=[[]for _ in range(1+n)],[0 for _ in range(1+n)]
while m:
	m-=1
	a,b,c=[int(e) for e in si().split()]
	g[a].append([b,c])
	g[b].append([a,c])
	
cost[s]=int(1e6)+1
pq=[]
heapq.heappush(pq,[-cost[s],s])
while pq:
	cp=heapq.heappop(pq)
	if -cp[0]<cost[cp[1]]:continue
	for np in g[cp[1]]:
		w=min(-cp[0],np[1])
		if cost[np[0]]<w:
			cost[np[0]]=w
			heapq.heappush(pq,[-w,np[0]])

print(cost[e])
		
	
