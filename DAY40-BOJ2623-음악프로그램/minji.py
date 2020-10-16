import sys
from collections import deque, defaultdict

def topology_sort():
    q = deque()
    for i in range(1, n+1):
        if degree[i] == 0:
            q.append(i)
    ans = []
    while q:
        node = q.popleft()
        ans.append(node)
        for i in path[node]:
            degree[i] -= 1
            if degree[i] == 0:
                q.append(i)

    if len(ans) != n:
        print(0)
    else:
        for a in ans:
            print(a)

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    degree = [0 for _ in range(n+1)]

    path = defaultdict(lambda: [])

    for _ in range(m):
        nodes = list(map(int, sys.stdin.readline().split()))[1:]
        for i in range(len(nodes)-1):
            path[nodes[i]].append(nodes[i+1])
            degree[nodes[i+1]] += 1
    topology_sort()
