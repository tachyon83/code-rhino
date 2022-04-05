import sys
import heapq

INF = sys.maxsize

def dijkstra(n, s, graph):
    dp = [INF for _ in range(n+1)]
    dp[s] = 0
    
    hq = []
    heapq.heappush(hq, [0, s])
    
    while hq:
        cost, node = heapq.heappop(hq)
        
        if cost > dp[node]:
            continue
        
        for vertex in graph[node]:
            neighbor = vertex[0]
            new_cost = dp[node] + vertex[1]
            
            if new_cost < dp[neighbor]:
                dp[neighbor] = new_cost
                heapq.heappush(hq, [new_cost, neighbor])
    
    return dp

for _ in range(int(sys.stdin.readline())):
    n, m, t = map(int, sys.stdin.readline().split())
    s, g, h = map(int, sys.stdin.readline().split())
    
    graph = [[] for _ in range(n+1)]
    
    for _ in range(m):
        a, b, d = map(int, sys.stdin.readline().split())
        
        if (a == g and b == h) or (a == h and b == g):
            d -= 0.1
        
        graph[a].append([b, d])
        graph[b].append([a, d])
    
    targets = []
    for _ in range(t):
        targets.append(int(sys.stdin.readline()))
    targets.sort()
    
    ans = dijkstra(n, s, graph)
    
    for target in targets:
        if ans[target] != INF and type(ans[target]) == float:
            print(target, end = ' ')
    print()
