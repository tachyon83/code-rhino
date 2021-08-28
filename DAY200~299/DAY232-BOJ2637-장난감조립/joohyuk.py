import sys
from collections import deque
si=sys.stdin.readline
n=int(si())
ins,g,cnt=[0 for _ in range(n+1)],[[]for _ in range(n+1)],[0 for _ in range(n+1)]
m=int(si())
while m:
	m-=1
	x,y,k=[int(e) for e in si().split()]
	ins[y]+=1
	g[x].append([y,k])

q,leaves=deque(),[]
for i in range(1,n+1):
	if not len(g[i]):
		leaves.append(i)
	if not ins[i]:
		q.append(i)

while q:
	curr=q.popleft()
	for np in g[curr]:
		if cnt[curr]:
			cnt[np[0]]+=cnt[curr]*np[1]
		else:cnt[np[0]]+=np[1]
		ins[np[0]]-=1
		if not ins[np[0]]:
			q.append(np[0])
			
for leaf in leaves:
	print(leaf,cnt[leaf])
	
