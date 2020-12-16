from collections import defaultdict, deque

def bfs(graph, root, visited):
    queue = deque([(root, 0)])
    ret = 0
    while queue:
        node, depth = queue.popleft()
        if not visited[node]:
            visited[node] = 1
            if ret < depth:
                ret = depth
            queue.extend([(n, depth + 1) for n in graph[node] if not visited[n]])
    return ret

N = int(input())
graph = [set() for _ in range(N + 1)]

while True:
    frm, to = map(int, input().split())
    if frm == -1: break
    graph[frm].add(to)
    graph[to].add(frm)

ret_dict = defaultdict(list)
for node in range(1, N + 1):
    ret = bfs(graph, node, [0] * (N + 1))
    ret_dict[ret].append(node)
    
ans = max(ret_dict.items(), key= lambda x: x[1])
print(ans[0], len(ans[1]))
print(*ans[1])
