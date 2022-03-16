import sys
input=sys.stdin.readline
N,M=map(int,input().split())
arr=list(map(int,input().split()))

if N<=M:
    print(N)
else:
    start,end=0,60000000000
    while start<=end:
        mid=(start+end)//2
        num=M
        for i in range(M):
            num+=mid//arr[i]

        if num>=N:
            time=mid
            end=mid-1
        else:
            start=mid+1
    
    num=M
    for i in range(M):
        num+=(time-1)//arr[i]
    
    for i in range(M):
        if time%arr[i]==0:
            num+=1
        if num==N:
            print(i+1)
            break

