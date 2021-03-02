from sys import stdin

input = stdin.readline
INF = int(1e9)

N, M = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)
distance = [INF] * (N+1)


for _ in range(N-1):
    u, v, value = map(int, input().split())
    graph[u].append([v, value])

def get_smallest_node():
    min_value = INF
    index = 0
    for i in range(1, N+1):
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i]
            index = i
    return index

def dijkstra(start):
    distance = [INF] * (N+1)
    distance[start] = 0
    visited[start] = True
    for j in graph[start]:
        distance[j[0]] = j[1]

    for i in range(N-1):
        now = get_smallest_node()
        visited[now] = True

        for j in graph[now]:
            cost = distance[now] + j[1]
            if cost < distance[j[0]]:
                distance[j[0]] = cost
    return distance

for _ in range(M):
    n1, n2 = map(int, input().split())
    distance = dijkstra(n1)
    print(distance[n2])
