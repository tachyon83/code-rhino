import sys
input = sys.stdin.readline
 
def farthest(i):
    stack = tree[i][:]
    visit = [False] * 10001
    visit[i] = True
    node, dist = 0, 0
 
    for sn, sd in stack:
        visit[sn] = True
        if sd > dist:
            node = sn
            dist = sd
 
    while stack:
        sn, sd = stack.pop()
        link = tree[sn]
        for ln, ld in link:
            if not visit[ln]:
                visit[ln] = True
                now = sd + ld
                stack.append((ln, now))
                if now > dist:
                    node = ln
                    dist = now
    
    return node, dist
 
n = int(input())
tree = {}
key = []
for _ in range(n-1):
    v1, v2, weight = map(int, input().split())
    if not v1 in key:
        tree[v1] = []
        key.append(v1)
    if not v2 in key:
        tree[v2] = []
        key.append(v2)
    tree[v1].append((v2, weight))
    tree[v2].append((v1, weight))
 
edge, dist = farthest(1)
print(farthest(edge)[1])
