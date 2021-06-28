import sys
input=sys.stdin.readline

n,m=map(int,input().split())
memorys=list(map(int,input().split()))
times=list(map(int,input().split()))

dp=[0]*(sum(times)+1)

for i in range(n):
    time=times[i];memory=memorys[i]
    for j in range(len(dp)-1,time-1,-1):
        dp[j]=max(dp[j],dp[j-time]+memory)

answer=0
while dp[answer]<m:
    answer+=1
print(answer)
