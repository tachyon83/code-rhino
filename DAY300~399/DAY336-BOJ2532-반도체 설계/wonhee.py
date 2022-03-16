import sys
from bisect import bisect_left
input=sys.stdin.readline

n=int(input())
arr=list(map(int,input().split()))

result=[]
for i in range(n):
    if len(result)==0 or result[-1]<arr[i]:
        result.append(arr[i])
    else:
        idx=bisect_left(result,arr[i])
        result[idx]=arr[i]

print(len(result))
