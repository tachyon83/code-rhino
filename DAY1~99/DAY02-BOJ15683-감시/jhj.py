dp=dict()
dp[0],dp[1],mod=1,1,10007

n=int(input())
if n==1: print(dp[1])
else:
    for i in range(2,n+1): dp[i]=((dp[i-2]*2)%mod+dp[i-1])%mod
    print(dp[n])
