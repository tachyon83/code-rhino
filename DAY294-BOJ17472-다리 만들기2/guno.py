import sys
from collections import deque
input=sys.stdin.readline

n,m=map(int,input().split())
MAP=[list(map(int,input().split())) for _ in range(n)]

dx,dy=[0,0,1,-1],[1,-1,0,0]
islandNum=2
islands=[]
INF=200

for i in range(n):
    for j in range(m):
        if MAP[i][j]==1:
            q=deque()
            MAP[i][j]=islandNum
            temp=[(i,j)]
            q.append((i,j))
            while q:
                x,y=q.popleft()
                for k in range(4):
                    nx,ny=x+dx[k],y+dy[k]
                    if 0<=nx<n and 0<=ny<m and MAP[nx][ny]==1:
                        MAP[nx][ny]=islandNum
                        q.append((nx,ny))
                        temp.append((nx,ny))
            islands.append(temp)
            islandNum+=1

islandNum-=2
iGraph=[[INF] *islandNum for _ in range(islandNum)]

def getBridge(x,y,k):
    Id=MAP[x][y]
    bridgelen=0
    while True:
        x+=dx[k]
        y+=dy[k]
        if not 0<=x<n or not 0<=y<m:
            return (bridgelen,-1)
        if MAP[x][y]!=0:
            return (bridgelen,MAP[x][y])
        bridgelen+=1

for island in islands:
    for x,y in island:
        for k in range(4):
            bridgelen,target=getBridge(x,y,k)
            if bridgelen>1 and target>1:
                target-=2
                now=MAP[x][y]-2
                iGraph[now][target]=min(iGraph[now][target],bridgelen)
                iGraph[target][now]=min(iGraph[target][now],bridgelen)
vertexs=[]
for i in range(islandNum):
    for j in range(i+1,islandNum):
        if iGraph[i][j]!=INF:
            vertexs.append((i,j,iGraph[i][j]))
vertexs.sort(key=lambda x:x[2])
sets=[]
answer=0
for i1,i2,length in vertexs:
    cycle=False
    setIdx1,setIdx2=-1,-2
    for setIdx,s in enumerate(sets):
        if i1 in s:
            setIdx1=setIdx
        if i2 in s:
            setIdx2=setIdx
    if setIdx1==setIdx2:
        cycle=True
    if not cycle:
        if setIdx1<0 and setIdx2<0:
            temp=set()
            temp.add(i1)
            temp.add(i2)
            sets.append(temp)
        elif setIdx1>=0 and setIdx2<0:
            sets[setIdx1].add(i2)
        elif setIdx2>=0 and setIdx1<0:
            sets[setIdx2].add(i1)  
        else:
            sets[setIdx1]|=sets[setIdx2]
            sets.pop(setIdx2)
        answer+=length
if sets and all( (i in sets[0]) for i in range(islandNum)):
    print(answer)
else:
    print(-1)
