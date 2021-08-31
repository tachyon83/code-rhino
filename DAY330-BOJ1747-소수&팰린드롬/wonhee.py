import sys
input=sys.stdin.readline

arr=[0 for _ in range(2000001)]
arr[1]=1
for i in range(1,2000001):
    if arr[i]==1:
        continue
    j=2
    while i*j<2000001:
        arr[i*j]=1
        j+=1

N=int(input())
while 1:
    if arr[N]==0 and str(N)==str(N)[::-1]:
        break
    N+=1

print(N)