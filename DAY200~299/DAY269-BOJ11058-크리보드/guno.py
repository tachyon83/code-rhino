import sys
input=sys.stdin.readline

n=int(input())
arr=[i for i in range(7)]
for i in range(7,n+1):
    arr.append(max(arr[i-3]*2,arr[i-4]*3,arr[i-5]*4))
print(arr[n])
