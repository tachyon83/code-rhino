import sys
from bisect import bisect_left,bisect_right
input=sys.stdin.readline

T=int(input())
n=int(input())
A=list(map(int,input().split()))
m=int(input())
B=list(map(int,input().split()))

sumA,sumB=[],[]
for i in range(n):
    sum=A[i]
    sumA.append(sum)
    for j in range(i+1,n):
        sum+=A[j]
        sumA.append(sum)

for i in range(m):
    sum=B[i]
    sumB.append(sum)
    for j in range(i+1,m):
        sum+=B[j]
        sumB.append(sum)

sumA.sort()
sumB.sort()
result=0
for a in sumA:
    result+=(bisect_right(sumB,T-a)-bisect_left(sumB,T-a))
print(result)