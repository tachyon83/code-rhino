import sys,math
si=sys.stdin.readline

mn,mx=0,int(1e9)
n,m=[int(e) for e in si().split()]
sz=1<<math.ceil(math.log2(n))+1
seg,idx=[[mx,mn]for _ in range(sz)],sz//2

for _ in range(n):
	temp=int(si())
	seg[idx]=[temp,temp]
	idx+=1
	
def construct():
	global seg
	for i in range(sz//2-1,0,-1):
		seg[i]=[min(seg[i<<1][0],seg[i<<1|1][0]),max(seg[i<<1][1],seg[i<<1|1][1])]
	
def find(a,b,i,j,idx):
	global seg
	if a>j or b<i: return [mx,mn]
	if a<=i and j<=b:return seg[idx]
	mid=(i+j)//2
	temp1=find(a,b,i,mid,idx<<1)
	temp2=find(a,b,mid+1,j,idx<<1|1)
	return [min(temp1[0],temp2[0]),max(temp1[1],temp2[1])]
	
construct()
while m:
	m-=1
	a,b=[int(e) for e in si().split()]
	print(*find(a,b,1,sz//2,1))
		
