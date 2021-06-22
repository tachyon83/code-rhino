import sys
input=sys.stdin.readline

t=int(input())
nums=[int(input()) for i in range(t)]
mod=1000000009
m=max(nums)
dp=[0]*(m+1)
dp[1]=1;dp[2]=2;dp[3]=4
for i in range(4,m+1):
    dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod

for num in nums:
    print(dp[num])
