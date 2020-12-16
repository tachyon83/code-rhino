import sys
from collections import deque

def sol():
    odd_v = 0
    q = deque([0])
    visited[0] = True

    for e_val in e.values():
        if len(e_val) % 2 !=0:
            odd_v += 1

    while q:
        x = q.popleft()
        for i in e[x]:
            if visited[i] == False:
                visited[i] = True
                q.append(i)

    if all(visited) and (odd_v == 0 or odd_v == 2):
        return "YES"
    else:
        return "NO"

if __name__ == "__main__":
    vertex, edge = map(int, sys.stdin.readline().split())
    e = dict()
    visited = [False] * vertex
    for i in range(0, edge):
        v1, v2 = map(int, sys.stdin.readline().split())
        v1, v2 = v1-1, v2-1
        e.setdefault(v1, []).append(v2)
        e.setdefault(v2, []).append(v1)

    print(sol())
