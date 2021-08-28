import sys
si=sys.stdin.readline

n,t,mod,s=int(si()),(1<<10)-1,int(1e9),0
dp=[[[0 for _ in range(t+1)]for _ in range(10)]for _ in range(100+1)]

def solve(i,m,v):
	global n,t
	if dp[i][m][v]:return dp[i][m][v]
	if i==n:
		if v==t:return 1
		else:return 0
	if m==9:dp[i][m][v]=solve(i+1,8,v|(1<<8))
	elif not m:dp[i][m][v]=solve(i+1,1,v|(1<<1))
	else:dp[i][m][v]=(solve(i+1,m-1,v|(1<<(m-1)))+solve(i+1,m+1,v|(1<<(m+1))))%mod
	return dp[i][m][v]

for i in range(1,10):s=(s+solve(1,i,1<<i))%mod
print(s)
	
