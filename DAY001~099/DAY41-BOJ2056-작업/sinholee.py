n = int(input())
adj_list = [[] for _ in range(n+1)]
outer_adj_list = [[] for _ in range(n+1)]
tasks = [0] * (n+1)
inner_degree = [0] * (n+1)
dp = [0] * (n+1)
visited = [0] * (n+1)
for i in range(1, n+1):
    temp = list(map(int, input().split()))
    tasks[i] = temp[0]
    for _ in range(temp[1]):
        adj_list[temp[_+2]].append(i)
        outer_adj_list[i].append(temp[_+2])
        inner_degree[i] += 1

for i in range(n): # 번 반복
    target_node = None
    for node in range(1, n+1): # 각 노드번호
        if not visited[node] and not inner_degree[node]:
            target_node = node
            visited[node] = 1
            break
    for j in adj_list[node]:
        inner_degree[j] -= 1
    max_time = 0
    for k in outer_adj_list[node]:
        max_time = max(max_time, dp[k])
    dp[node] = max_time + tasks[node]
print(max(dp))



