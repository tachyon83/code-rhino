from collections import defaultdict, deque

def dfs_recursive(graph, node, visited):
    if node in visited:
        return
    visited.append(node)
    for n in graph[node]:
        dfs_recursive(graph, n, visited)
    return visited


def dfs(graph, root, visited):
    stack = deque([root])

    while stack:
        n = stack.pop()
        if n in visited: continue
        visited.append(n)
        stack.extend(sorted(graph[n] - set(visited))[::-1])
#         stack.extend(reversed(list(graph[n] - set(visited))))
    return visited

def bfs(graph, root, visited):
    queue = deque([root])
    while queue:
        n = queue.popleft()
        if n in visited: continue
        visited.append(n)
        queue.extend(sorted(graph[n] - set(visited)))
    return visited


N, M, V = map(int, input().split())
graph = defaultdict(set)


for i in range(M):
    n1, n2 = map(int, input().split())
    graph[n1].add(n2)
    graph[n2].add(n1)
    
print(*dfs_recursive(graph, V, []))
# print(*dfs(graph, V, []))
print(*bfs(graph, V, []))
