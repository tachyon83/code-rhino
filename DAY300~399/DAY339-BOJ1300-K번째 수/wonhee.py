import sys
input=sys.stdin.readline

N=int(input())
K=int(input())

start,end=1,K
while start<=end:
    mid=(start+end)//2
    cnt=0
    for i in range(1,N+1):
        cnt+=min(mid//i,N)
    if cnt<K:
        start=mid+1
    else:
        end=mid-1
        result=mid

print(result)