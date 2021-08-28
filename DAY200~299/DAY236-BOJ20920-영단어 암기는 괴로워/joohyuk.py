from sys import stdin
si=stdin.readline
n,m=[int(e) for e in si().split()]
words,cnt=[],dict()
for _ in range(n):
	word=si()[:-1]
	if len(word)>=m:
		words.append(word)
		if word not in cnt:
			cnt[word]=0
		cnt[word]+=1

def dnc(arr):
	global nums
	if len(arr)==1:return arr
	mid=len(arr)//2
	return compare(dnc(arr[:mid]),dnc(arr[mid:]))

def check(l,r):
	global cnt
	if cnt[l]>cnt[r]:return True
	if cnt[l]<cnt[r]:return False
	if len(l)>len(r):return True
	if len(l)<len(r):return False
	if l<r:return True
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

wordset=set()
for word in words:wordset.add(word)
ans=dnc(list(wordset))
for e in ans:print(e)
	
