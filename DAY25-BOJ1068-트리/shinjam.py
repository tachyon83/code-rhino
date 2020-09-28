from collections import defaultdict 

N = int(input())
input_nodes = map(int, input().split())
del_node = int(input())

nodes = defaultdict(list)

stack = []
visited = [0] * N
for idx, val in enumerate(input_nodes):
    if del_node in [idx, val]:
        continue
    if val == -1:
        stack.append(idx)
        continue
    nodes[idx].append(val)
    nodes[val].append(idx)


ret = 0
while stack:
    node = stack.pop()
    visited[node] = 1

    leaf = True
    for n in nodes[node]:
        if not visited[n]:
            stack.append(n)
            leaf = False
    if leaf:
        ret += 1

print(ret)
