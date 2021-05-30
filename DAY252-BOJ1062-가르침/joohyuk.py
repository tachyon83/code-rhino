import sys
from itertools import combinations as cb
si=sys.stdin.readline

n,k=[int(e) for e in si().split()]
given,base='antic',0
for e in given:base|=1<<(ord(e)-ord('a'))
words,abc=[],set()
for _ in range(n):
	temp=si()[:-1]
	temp,mask=temp[4:-4],0
	for e in temp:
		if e in given:continue
		v=ord(e)-ord('a')
		abc.add(v)
		mask|=1<<v
	words.append(mask)

mx=0
if k<5:print(0)
elif k-5>len(abc):print(n)
else:
	cases=cb(list(abc),k-5)
	for case in cases:
		mask,cnt=base,0
		for e in case:mask|=1<<e
		for word in words:
			if (word|mask)==mask:cnt+=1
		mx=max(mx,cnt)
	print(mx)
