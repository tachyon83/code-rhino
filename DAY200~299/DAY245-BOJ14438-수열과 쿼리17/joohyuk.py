import sys,math
si=sys.stdin.readline

n,big=int(si()),int(1e9)+1
sz=1<<(math.ceil(math.log2(n))+1)
given,seg=[int(e) for e in si().split()],[0 for _ in range(sz)]

def form(sz):
	i=sz//2
	for e in given:
		seg[i]=e
		i+=1
	for i in range(sz//2-1,0,-1):seg[i]=min(seg[i<<1],seg[i<<1|1])
form(sz)

def update(sz,i,a):
	i=sz//2+i-1
	seg[i]=a
	i//=2
	while i>0:
		seg[i]=min(seg[i<<1],seg[i<<1|1])
		i>>=1

def find(i,j,s,e,idx):
	global big
	if s>j or e<i:return big
	if i<=s and e<=j:return seg[idx]
	mid=(s+e)//2
	return min(find(i,j,s,mid,idx<<1),find(i,j,mid+1,e,idx<<1|1))

m=int(si())
while m:
	m-=1
	q,i,j=[int(e) for e in si().split()]
	if q-1:print(find(i,j,1,sz//2,1))
	else:update(sz,i,j)
	
