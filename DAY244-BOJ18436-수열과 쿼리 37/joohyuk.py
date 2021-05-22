import sys,math
si=sys.stdin.readline

n=int(si())
sz=1<<(math.ceil(math.log2(n))+1)
seg=[[0,0]for _ in range(sz)]
nums=[int(e) for e in si().split()]

def construct(sz):
	idx=sz//2
	for num in nums:
		if not num%2:seg[idx][0]=1
		else:seg[idx][1]=1
		idx+=1
	
	for i in range(sz//2-1,0,-1):
		seg[i][0]=seg[i<<1][0]+seg[i<<1|1][0]
		seg[i][1]=seg[i<<1][1]+seg[i<<1|1][1]

construct(sz)

def update(i,x,sz):
	i=sz//2+i-1
	if not x%2:seg[i]=[1,0]
	else:seg[i]=[0,1]
	
	i//=2
	while i>0:
		seg[i][0]=seg[i<<1][0]+seg[i<<1|1][0]
		seg[i][1]=seg[i<<1][1]+seg[i<<1|1][1]
		i//=2
		
def find(s,e,i,j,idx,q):
	if s>j or e<i:return 0
	if s<=i and j<=e:
		if not q-2:return seg[idx][0]
		else: return seg[idx][1]
	mid=(i+j)//2
	return find(s,e,i,mid,idx<<1,q)+find(s,e,mid+1,j,idx<<1|1,q)

m=int(si())
while m:
	m-=1
	q,l,r=[int(e) for e in si().split()]
	if q==1:
		update(l,r,sz)
	else:
		print(find(l,r,1,sz//2,1,q))
	
	
