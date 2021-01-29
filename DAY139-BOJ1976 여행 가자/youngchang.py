N = int(input())
M = int(input())
graph = []
for _ in range(N):
    row = list(map(int, input().split()))
    graph.append(row)
plan = list(map(int, input().split()))
plan = [i - 1 for i in plan]

dist = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if i == j: continue
        dist[i][j] = 1 if graph[i][j] else float('inf')

for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(1, len(plan)):
    st = plan[i - 1]
    ed = plan[i]
    if dist[st][ed] == float('inf'):
        print("NO")
        break
else:
    print("YES")