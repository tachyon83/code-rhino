from sys import stdin
si=stdin.readline
n,c=[int(e) for e in si().split()]
nums=[int(e) for e in si().split()]
cnt=dict()
for i,num in enumerate(nums):
	if num not in cnt:cnt[num]=[0,i]
	cnt[num][0]+=1

def dnc(arr):
	global nums
	if len(arr)==1:return arr
	mid=len(arr)//2
	return compare(dnc(arr[:mid]),dnc(arr[mid:]))

def check(l,r):
	global cnt
	if cnt[l][0]>cnt[r][0]:return True
	if cnt[l][0]<cnt[r][0]:return False
	if cnt[l][1]<cnt[r][1]:return True
	return False
		
def compare(la,ra):
	li,ri,lsz,rsz,arr=0,0,len(la),len(ra),[]
	while li<lsz and ri<rsz:
		if check(la[li],ra[ri]):
			arr.append(la[li])
			li+=1
		else:
			arr.append(ra[ri])
			ri+=1
	while li<lsz:
		arr.append(la[li])
		li+=1
	while ri<rsz:
		arr.append(ra[ri])
		ri+=1
	return arr

print(*dnc(nums))
	
