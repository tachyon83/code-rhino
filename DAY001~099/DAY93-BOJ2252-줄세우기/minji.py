import sys
from collections import deque, defaultdict

def topology_sort():
    q = deque()
    for i in range(1, n+1):
        if degree[i] == 0:
            q.append(i)
    ans = []
    while q:
        student = q.popleft()
        ans.append(student)
        for i in h[student]:
            degree[i] -= 1
            if degree[i] == 0:
                q.append(i)
    for i in range(len(ans)):
        print (ans[i], end= " ")

if __name__ == "__main__":
    n, m = list(map(int, sys.stdin.readline().split()))
    degree = [0 for _ in range(n+1)]
    h = defaultdict(list)

    for _ in range(m):
        a, b = list(map(int, sys.stdin.readline().split()))
        h[a].append(b)
        degree[b] += 1

    topology_sort()
