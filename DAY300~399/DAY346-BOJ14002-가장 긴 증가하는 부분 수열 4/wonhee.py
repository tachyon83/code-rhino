import sys
input=sys.stdin.readline

N=int(input())
arr=list(map(int,input().split()))

dp=[1 for _ in range(N)]

for i in range(N):
    for j in range(i):
        if arr[i]>arr[j]:
            dp[i]=max(dp[i],dp[j]+1)

length=max(dp)
print(length)

result=[]
for i in range(N-1,-1,-1):
    if dp[i]==length:
        result.append(arr[i])
        length-=1

result.reverse()
for a in result:
    print(a,end=' ')