import sys
si=sys.stdin.readline

n=1
while n:
	n,k=[int(e) for e in si().split()]
	if not n:break
	nums,idx=[int(e) for e in si().split()],0
	p,d=dict(),dict()
	for num in nums:
		p[num],d[num]=0,0
	
	for i,num in enumerate(nums):
		if not i:continue
		if nums[i]>nums[i-1]+1:
			if i-1:idx+=1
			p[num]=nums[idx]
			d[num]=d[nums[idx]]+1
		else:
			p[num]=nums[idx]
			d[num]=d[nums[idx]]+1
	
	if d[k]<2:
		print(0)
		continue
	
	nodes_depth=dict()
	for num in nums:
		if d[num] not in nodes_depth:
			nodes_depth[d[num]]=[]
		nodes_depth[d[num]].append(num)
	
	cnt=0
	for node in nodes_depth[d[k]]:
		if p[node]!=p[k] and p[p[node]]==p[p[k]]:cnt+=1
	print(cnt)
	
