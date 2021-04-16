from collections import defaultdict


N, M = map(int, input().split())

dist = defaultdict(dict)
for _ in range(N - 1):
    i, j, d = map(int, input().split())
    dist[i][j] = d
    dist[j][i] = d
    
def bfs(st, ed):
    seen = set()
    q = [(st, 0)]
    for node, d in q:
        if node in seen: continue
        seen.add(node)
        if node == ed: break
        for nei in dist[node]:
            q.append((nei, d + dist[node][nei]))
    return d

for _ in range(M):
    st, ed = map(int, input().split())
    print(bfs(st, ed))