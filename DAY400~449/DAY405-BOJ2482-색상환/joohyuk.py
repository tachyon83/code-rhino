import sys
si=sys.stdin.readline
sys.setrecursionlimit(1000+5)

n,k,mod=int(si()),int(si()),int(1e9+3)
vis,dp=[0 for _ in range(n)],[-1 for _ in range(n)]

def solve(pos,f,cnt):
    if not cnt:return 1
    global n,mod
    if pos==n-1:
        if cnt>1 or f:return 0
        return 1
    if dp[pos]!=-1:return dp[pos]
    ret=0
    for i in range(pos+1+1,n):ret=(ret+solve(i,f,cnt-1))%mod
    dp[pos]=ret
    return dp[pos]

print((solve(0,1,k-1)+solve(1,0,k-1))%mod)
