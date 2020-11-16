import heapq

INF=9876543210
n,m=map(int,input().split())
graph={}
for i in range(n+1):
    graph[i]=[]
for i in range(m):
    a,b,c=map(int,input().split())
    graph[a].append([b,c])
    graph[b].append([a,c])

def dijstra(startNode):
    global cnt

    nodeDist=[INF for i in range(n+1)]
    dij=[]
    nodeDist[startNode]=0
    for conNode,cost in graph[startNode]:
        heapq.heappush(dij,[cost,conNode,conNode])
        nodeDist[conNode]=cost
    while(dij):
        nowCost,nowNode,stNode=heapq.heappop(dij)
        if nodeDist[nowNode]<nowCost:
            continue
        #현재노드 최신화
        ansL[startNode-1][nowNode-1]=stNode
        cnt+=1
        if cnt==n:
            return
        #연결노드찾기
        for conNode,addedCost in graph[nowNode]:
            toCost=addedCost+nowCost
            if toCost<nodeDist[conNode]:
                nodeDist[conNode]=toCost
                heapq.heappush(dij,[toCost,conNode,stNode])

#다익스트라시작
ansL=[["-" for j in range(n)] for i in range(n)]
for i in range(1,n+1):
    cnt=1
    dijstra(i)

for i in ansL:
    print(*i)
