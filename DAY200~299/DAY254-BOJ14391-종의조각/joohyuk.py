import sys
si=sys.stdin.readline

n,m=[int(e) for e in si().split()]
board,ans=[],0
vis=[[False for _ in range(m)]for _ in range(n)]

for _ in range(n):
	row=[int(e) for e in si().strip()]
	board.append(row)

def solve(num,s):
	global n,m,ans
	if num>n*m-1:
		ans=max(ans,s)
		return
	
	r,c=num//m,num%m
	
	if vis[r][c]:
		solve(num+1,s)
		return
	
	vis[r][c]=True
	curr,i,broken=board[r][c],0,False
	for i in range(1,m-c):
		if vis[r][c+i]:
			broken=True
			break
		curr=10*curr+board[r][c+i]
		vis[r][c+i]=True

		solve(num+1,s+curr)
	for j in range(1,i if broken else i+1):vis[r][c+j]=False
	
	curr,flag,broken=board[r][c],False,False
	for i in range(1,n-r):
		flag=True
		if vis[r+i][c]:
			broken=True
			break
		curr=10*curr+board[r+i][c]
		vis[r+i][c]=True
        
		solve(num+1,s+curr)
	if flag:
		for j in range(1,i if broken else i+1):vis[r+j][c]=False
	
	solve(num+1,s+board[r][c])
	vis[r][c]=False
	
solve(0,0)
print(ans)
