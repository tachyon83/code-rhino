import sys
input=sys.stdin.readline

H,W=map(int,input().split())
arr=[]
resultArr=[[-1 for _ in range(W)] for _ in range(H)]
for _ in range(H):
    arr.append(input())
for i in range(H):
    for j in range(W):
        if arr[i][j]=='c':
            resultArr[i][j]=0

for i in range(H):
    print(resultArr[i][0],end=' ')
    for j in range(1,W):
        if resultArr[i][j-1]!=-1 and resultArr[i][j]!=0:
            resultArr[i][j]=resultArr[i][j-1]+1
        print(resultArr[i][j],end=' ')
    print()