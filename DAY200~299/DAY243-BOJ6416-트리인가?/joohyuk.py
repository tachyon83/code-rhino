import sys
from collections import deque
si=sys.stdin.readline
given,k,p=[1,1],1,dict()

while True:
	g,ins,p,vis=dict(),dict(),dict(),dict()
	finished=False
	while not finished:
		given=[int(e) for e in si().split()]
	# if not len(given):continue
		if len(given) and given[0]==-1:
			sys.exit(0)

		for i in range(0,len(given),2):
			if not given[i]:
				finished=True
				break
			a,b=given[i],given[i+1]
			if a not in g:
				g[a],ins[a],p[a],vis[a]=[],0,0,False
			if b not in g:
				g[b],ins[b],p[b],vis[b]=[],0,0,False
			g[a].append(b)
			ins[b]+=1
			p[b]=a
		if finished: break
	
	root,root_cnt,wrong_edges=0,0,0
	for e in g.keys():
		if not p[e]:
			root_cnt+=1
			root=e
		if ins[e]>1:
			wrong_edges+=1
	
	if not len(g.keys()):
		print('Case '+str(k)+' is a tree.')
		k+=1
		continue
		
	if root_cnt>1 or not root or wrong_edges:
		print('Case '+str(k)+' is not a tree.')
		k+=1
		continue

	flag,vis[root],q=False,True,deque()
	q.append(root)
	while q:
		curr=q.popleft()
		for nx in g[curr]:
			if vis[nx]:
				flag=True
				break
			vis[nx]=True
			q.append(nx)
		if flag:break
	
	for e in g.keys():
		if not vis[e]:
			flag=True
			break

	if flag:print('Case '+str(k)+' is not a tree.')
	else:print('Case '+str(k)+' is a tree.')
	k+=1
