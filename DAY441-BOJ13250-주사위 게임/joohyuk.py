import sys,bisect
si=sys.stdin.readline

n,dice,denom,mx=int(si()),6,6,int(6e6)
counts=[0 for _ in range(n)]
dp=[[[mx,0] for _ in range(dice)] for _ in range(n)]

for i in range(dice):dp[0][i]=[i+1,i+1]
if n<=dice:counts[0]=dice-n+1

for i in range(1,n):
    for j in range(dice):
        for k in range(dice):
            dp[i][j][0]=min(dp[i][j][0],j+1+dp[i-1][k][0])
            dp[i][j][1]=max(dp[i][j][1],j+1+dp[i-1][k][1])

        temp=[v-j-1 for v in range(dp[i][j][0],dp[i][j][1]+1)]
        idx=bisect.bisect_left(temp,n)
        counts[i]+=idx

ans=0
for i in range(n):
    ans+=(i+1)*counts[i]/denom
    denom*=dice
print(ans)
