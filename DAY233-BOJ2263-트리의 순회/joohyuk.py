import sys
si=sys.stdin.readline
sys.setrecursionlimit(int(1e5)+1)

n=int(si())
ino=[int(e) for e in si().split()]
posto=[int(e) for e in si().split()]
preo=[]

def solve(in_s,in_e,post_s,post_e):
	  global ino,posto,preo
	
  	preo.append(posto[post_e])
	  if in_s==in_e:return
  	idx=ino.index(posto[post_e])
	  pos=post_s+idx-in_s
  	if idx>in_s:solve(in_s,idx-1,post_s,pos-1)
	  if idx<in_e:solve(idx+1,in_e,pos,post_e-1)

solve(0,n-1,0,n-1)
print(*preo)
