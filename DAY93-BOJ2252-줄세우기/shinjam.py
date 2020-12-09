from collections import deque, defaultdict
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
indegrees = [0]*(N+1)
graph = defaultdict(list)
for _ in range(M):
    a, b = map(int, input().split())
    indegrees[b] += 1
    graph[a].append(b)

queue = deque(i for i in range(1, N+1) if indegrees[i]==0)

ans = []
while queue:
    num = queue.popleft()
    ans.append(num)
    for val in graph[num]:
        indegrees[val] -= 1
        if indegrees[val] == 0:
            queue.append(val)
print(*ans)
