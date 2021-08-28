import sys
from collections import deque
si=sys.stdin.readline

n,k=[int(e) for e in si().split()]
big,i=k+1,0
plugs=[deque() for _ in range(k+1)]

plans=[int(e) for e in si().split()]
for plan in plans:
	plugs[plan].append(i+1)
	i+=1
for i in range(1,k+1):plugs[i].append(big)

cnt,hold=0,set()
for plan in plans:
	plugs[plan].popleft()
	if len(hold)<n or plan in hold:
		hold.add(plan)
		continue
	mx,which=-1,0
	for e in hold:
		if plugs[e][0]>mx:
			mx,which=plugs[e][0],e
	hold.remove(which)
	hold.add(plan)
	cnt+=1

print(cnt)
