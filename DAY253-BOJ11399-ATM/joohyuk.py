import sys
si=sys.stdin.readline

n,ans,temp=int(si()),0,0
num=[int(e) for e in si().split()]
num.sort()

for e in num:
	temp+=e
	ans+=temp
print(ans)
	
