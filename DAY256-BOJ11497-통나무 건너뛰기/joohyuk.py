from collections import deque
import sys
si=sys.stdin.readline

t=int(si())
while t:
	t-=1
	n=int(si())
	trees=[int(e) for e in si().split()]
	trees.sort()
	
	dq,side,ans=deque(),0,0
	for tree in trees:
		if not dq:dq.append(tree)
		else:
			if side:
				ans=max(ans,abs(dq[-1]-tree))
				dq.append(tree)
			else:
				ans=max(ans,abs(dq[0]-tree))
				dq.appendleft(tree)
		side=(side+1)%2
	print(ans)
