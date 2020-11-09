from collections import defaultdict

def check(graph):
    odd = 0
    for val in graph.values():
        if len(val) % 2 != 0:
            odd += 1     
    return True if odd in [0, 2] else False

    
graph = defaultdict(list)

V, E = map(int, input().split())
for _ in range(E):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

print('YES' if check(graph) else 'NO')
