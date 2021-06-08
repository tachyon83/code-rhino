import sys
si=sys.stdin.readline

t=int(si())
while t:
	t-=1
	n=int(si())
	prices=[int(e) for e in si().split()]
	tot,mx=0,-1
	for i in range(n-1,-1,-1):
		if prices[i]>=mx:mx=prices[i]
		else:tot+=mx-prices[i]
	print(tot)
		
