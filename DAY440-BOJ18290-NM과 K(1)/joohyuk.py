import sys
si=sys.stdin.readline

n,m,k=[int(e) for e in si().split()]
board,vis=[],[[False for _ in range(m)]for _ in range(n)]
for i in range(n):board.append([int(e) for e in si().split()])

ans,curr=int(-100e6),0

def check(i,j):
    global n,m
    dr,dc=[0,1,0,-1],[1,0,-1,0]
    for k in range(4):
        nr,nc=i+dr[k],j+dc[k]
        if 0<=nr<n and 0<=nc<m:
            if vis[nr][nc]:return False
    return True


def solve(num,c):
    global ans,curr,n,m
    i,j=num//n,num%m
    if num>=n*m:return
    if not c:
        ans=max(ans,curr)
        return
    for ii in range(2):
        if ii:
            if check(i,j):
                curr+=board[i][j]
                vis[i][j]=True
                c-=1
                solve(num+1,c)
                c+=1
                vis[i][j]=False
                curr-=board[i][j]
        else:solve(num+1,c)

solve(0,k)
print(ans)
