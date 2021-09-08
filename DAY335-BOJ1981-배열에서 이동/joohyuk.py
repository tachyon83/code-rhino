import sys
from collections import deque
si=sys.stdin.readline

n,board=int(si()),[]
dr,dc=[0,1],[1,0]
for _ in range(n):
	row=[int(e) for e in si().split()]
	board.append(row)

q,ans=deque(),201
q.append([[0,0],[board[0][0],board[0][0]]])
while q:
	cp=q.popleft()
	ccrds,cvp=cp
	cr,cc=ccrds
	cmn,cmx=cvp
	
	if cr==n-1 and cc==n-1:
		ans=min(ans,cmx-cmn)
		continue
	
	for i in range(2):
		nr,nc=cr+dr[i],cc+dc[i]
		if nr>=n or nc>=n:continue
		nmn,nmx=cvp
		if board[nr][nc]<cmn:nmn=board[nr][nc]
		elif board[nr][nc]>cmx:nmx=board[nr][nc]
		q.append([[nr,nc],[nmn,nmx]])

print(ans)
