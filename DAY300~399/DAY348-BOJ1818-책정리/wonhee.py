import sys
from bisect import bisect_left
input=sys.stdin.readline

N=int(input())
arr=list(map(int,input().split()))


lis=[]
for i in range(N):
    if lis==[] or lis[-1]<arr[i]:
        lis.append(arr[i])
    else:
        idx=bisect_left(lis,arr[i])
        lis[idx]=arr[i]

print(N-len(lis))
