import sys
si=sys.stdin.readline

n,m=int(si()),0
cost=[0 for _ in range(n+1)]
for i in range(n):
	l=[int(e) for e in si().split()]
	temp=0
	for j in range(l[1]):
		temp=max(temp,cost[l[j+2]])
	cost[i+1]=temp+l[0]
	m=max(m,cost[i+1])
print(m)
	
