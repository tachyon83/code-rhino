import sys
si=sys.stdin.readline

n=1
while n:
	n,k=[int(e) for e in si().split()]
	if not n:break
	nums=[int(e) for e in si().split()]
	tree,prev,depth=dict(),0,0
	nodes_depth,hold,pgr,idx=[[]for _ in range(n+1)],[],[],0
	parents=dict()
	
	for num in nums:
		if not prev:
			pgr=[num]
			nodes_depth[depth].append(num)
			depth+=1
			parents[num]=prev
			prev=num
			continue
			
		if num>prev+1:
			if not hold:
				hold=[num]
				nodes_depth[depth].append(num)
				prev=num
				continue
			
			tree[pgr[idx]]=[0,0]
			tree[pgr[idx]][0]=depth-1
			tree[pgr[idx]][1]=hold
			for e in hold:
				parents[e]=pgr[idx]
			hold=[num]
			idx+=1
			if idx>=len(pgr):
				idx,pgr=0,nodes_depth[depth]
				depth+=1
			nodes_depth[depth].append(num)
		else:
			hold.append(num)
			nodes_depth[depth].append(num)
		prev=num

	tree[pgr[idx]]=[0,0]
	tree[pgr[idx]][0]=depth-1
	tree[pgr[idx]][1]=hold
	for e in hold:
		parents[e]=pgr[idx]
	idx+=1

	while idx<len(pgr):
		tree[pgr[idx]]=[0,0]
		tree[pgr[idx]][0]=depth-1
		tree[pgr[idx]][1]=[]
		idx+=1


	if pgr!=nodes_depth[depth]:
		pgr=nodes_depth[depth]
		idx=0
		while idx<len(pgr):
			tree[pgr[idx]]=[0,0]
			tree[pgr[idx]][0]=depth
			tree[pgr[idx]][1]=[]
			idx+=1
	
	curr_parent,cnt=parents[k],0
	for node in nodes_depth[tree[k][0]]:
		if parents[node]!=curr_parent and parents[parents[node]]==parents[curr_parent]:
			cnt+=1

	print(cnt)

		
