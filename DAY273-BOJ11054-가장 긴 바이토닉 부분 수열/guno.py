import sys
input=sys.stdin.readline

n=int(input())
nums=list(map(int,input().split()))
dp=[0]+[-1]*1000
l=[0]*n
r=[0]*n

for idx,num in enumerate(nums):
    dp[num]=max(dp[:num])+1
    l[idx]=dp[num]

dp=[0]+[-1]*1000
nums.reverse()
for idx,num in enumerate(nums):
    dp[num]=max(dp[:num])+1
    r[idx]=dp[num]
r.reverse()
print(max(l[i]+r[i] for i in range(n))-1
