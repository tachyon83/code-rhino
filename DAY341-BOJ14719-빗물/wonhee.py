import sys
input=sys.stdin.readline
H,W=map(int,input().split())
arr=list(map(int,input().split()))

result=0
for i in range(1,W-1):
    left,right=0,0
    for j in range(i):
        left=max(left,arr[j])
    for j in range(i+1,W):
        right=max(right,arr[j])
    minNum=min(left,right)
    if minNum>arr[i]:
        result+=minNum-arr[i]
    
print(result)

