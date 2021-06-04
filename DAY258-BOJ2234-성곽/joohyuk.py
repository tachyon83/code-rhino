import sys
from collections import deque
si=sys.stdin.readline

m,n=[int(e) for e in si().split()]
board=[]
v=[[-1 for _ in range(m)]for _ in range(n)]
t=[[-1 for _ in range(m)]for _ in range(n)]
nums,dr,dc=[],[0,-1,0,1],[-1,0,1,0]

for _ in range(n):
	row=[int(e) for e in si().split()]
	board.append(row)

def bfs(coord,num):
    global n,m
    v[coord[0]][coord[1]]=num
    q,cnt=deque(),1
    q.append(coord)
    while q:
        cr,cc=q.popleft()
        mask=board[cr][cc]
        for idx in range(4):
            if not (mask&(1<<idx)):
                nr,nc=cr+dr[idx],cc+dc[idx]
                if 0<=nr<n and 0<=nc<m and v[nr][nc]==-1:
                    v[nr][nc]=num
                    cnt+=1
                    q.append([nr,nc])
    return cnt
                    
num=0
for i in range(n):
	for j in range(m):
		if v[i][j]==-1:
			nums.append(bfs([i,j],num))
			num+=1

print(len(nums))
print(max(nums))

mx=0
for i in range(n):
    for j in range(m):
        t[i][j]=nums[v[i][j]]

for cr in range(n):
    for cc in range(m):
        mask=board[cr][cc]
        for idx in range(4):
            if mask&(1<<idx):
                nr,nc=cr+dr[idx],cc+dc[idx]
                if 0<=nr<n and 0<=nc<m and v[cr][cc]!=v[nr][nc]:
                    mx=max(mx,t[cr][cc]+t[nr][nc])
print(mx)
