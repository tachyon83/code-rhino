import sys
input=sys.stdin.readline
d=[[-1,0],[1,0],[0,-1],[0,1]] 
 
times=0
r,c=map(int,input().split())
arr=[]
for _ in range(r):
    arr.append(list(map(int,input().split())))

while 1:
    cheeseNum=0
    for i in range(1,r-1):
        for j in range(1,c-1):
            cheeseNum+=arr[i][j]

    if cheeseNum==0:
        break
    else:
        remainCheese=cheeseNum

    check=[[0 for _ in range(c)] for _ in range(r)]
    q=[[0,0]]
    check[0][0]=1

    while q:
        y,x=q[0]
        q.pop(0)

        for i in range(4):
            ny,nx=y+d[i][0],x+d[i][1]
            if 0<=nx<c and 0<=ny<r and check[ny][nx]==0 and arr[ny][nx]==0:
                q.append([ny,nx])
                check[ny][nx]=1

    for i in range(1,r-1):
        for j in range(1,c-1):
            if arr[i][j]==1:
                for k in range(4):
                     ny,nx=i+d[k][0],j+d[k][1]
                     if check[ny][nx]:
                         arr[i][j]=0
                         break
    times+=1;

print(times)
print(remainCheese)

