import sys
import heapq
input = sys.stdin.readline

V, E = map(int, input().split())
start = int(input())
start -= 1
adj_list = [{} for _ in range(V)]
for _ in range(E):
    u, j, w = map(int, input().split())
    # (a,b) = 노드, 가중치
    if adj_list[u-1].get(j-1) == None:
        adj_list[u-1][j-1] = w
    else:
        if adj_list[u-1][j-1] > w:
            adj_list[u - 1][j - 1] = w
distance = [V*E+1] * V
visited = [False] * V
distance[start] = 0
hq = []
heapq.heappush(hq, (distance[start], start))
while True:
    if len(hq) == 0:
        break
    # 반환되는거는 현재 노드번호
    dis_til_u, u = heapq.heappop(hq)
    visited[u] = True
    for v, w in adj_list[u].items():
        if visited[v] == False and distance[v] > dis_til_u + w:
            distance[v] = dis_til_u + w
            heapq.heappush(hq, (distance[v], v))
for item in distance:
    if item == V*E+1:
        print('INF')
    else:
        print(item)

