import sys
si=sys.stdin.readline
n,m=[int(e) for e in si().split()]
words,given=set(),set()
for _ in range(n):
	word=si().rstrip()
	words.add(word)
cnt=0
for _ in range(m):
	if si().rstrip() in words:cnt+=1
print(cnt)
	
