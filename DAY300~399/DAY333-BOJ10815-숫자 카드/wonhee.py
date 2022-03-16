import sys
input=sys.stdin.readline

N=int(input())
arr=list(map(int,input().split()))
arr.sort()
M=int(input())
arr2=list(map(int,input().split()))

for num in arr2:
    start=0
    end=N-1
    while start<=end:
        mid=(start+end)//2
        if num==arr[mid]:
            print(1,end=' ')
            break
        elif num>arr[mid]:
            start=mid+1
        elif num<arr[mid]:
            end=mid-1
    else:
        print(0,end=' ')