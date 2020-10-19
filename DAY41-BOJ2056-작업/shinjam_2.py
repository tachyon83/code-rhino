
N = int(input())

dp = [0]*(N+1)
costs = [0]*(N+1)
graph = [set() for _ in range(N+1)]
cnt_indegrees = [0]*(N+1)
queue = deque()

for i in range(1, N+1):
    costs[i], *prior = map(int, input().split())
    if len(prior) == 1:
        dp[i] = costs[i]
        queue.append(i)
        continue
    cnt_indegrees[i] = prior[0]
    for p in prior[1:]:
        graph[p].add(i)

while queue:
    cur = queue.popleft()
    for nxt in graph[cur]:
        dp[nxt] = max(dp[nxt], dp[cur]+costs[nxt])
        cnt_indegrees[nxt] -= 1
        if not cnt_indegrees[nxt]:
            queue.append(nxt)
print(max(dp))
