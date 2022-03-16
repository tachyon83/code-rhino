import sys
import heapq
si = sys.stdin.readline


def find(a):
    if root[a] == a:
        return a
    root[a] = find(root[a])
    return root[a]


def union(a, b):
    a, b = find(a), find(b)
    root[a] = b


v, E = [int(e) for e in si().split()]
root, pq, ans = [e for e in range(v+1)], [], 0
while E:
    E -= 1
    a, b, c = [int(e) for e in si().split()]
    heapq.heappush(pq, [c, (a, b)])
while pq:
    curr = heapq.heappop(pq)
    a, b = curr[1][0], curr[1][1]
    if find(a) != find(b):
        ans += curr[0]
        union(a, b)
print(ans)
