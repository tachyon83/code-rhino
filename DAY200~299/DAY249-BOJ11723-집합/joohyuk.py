import sys
si=sys.stdin.readline

m,v=int(si()),0
while m:
	m-=1
	o=[e for e in si().split()]
	q=o[0]
	if o[0][1]!='l' and o[0][0]!='e':n=int(o[1])
	if q[1]=='d':v|=1<<n
	elif q[0]=='c':print(1 if v&(1<<n) else 0)
	elif q[0]=='r':v&=(~(1<<n))
	elif q[0]=='t':v^=1<<n
	elif q[1]=='l':v=(1<<21)-1
	elif q[0]=='e':v=0
	
