import sys
from heapq import heappush, heappop

def dijkstra():
    heap = []
    heappush(heap, (0, s_city))
    dis = [sys.maxsize] * (n+1)
    dis[s_city] = 0

    while heap:
        cost, idx = heappop(heap)
        for end, cost_ in maps[idx]:
            if dis[end] > cost + cost_:
                dis[end] = cost + cost_
                heappush(heap, (cost + cost_, end))
    return dis[e_city]


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())

    maps = [[] for _ in range(n+1)]

    for _ in range(m):
        s, e, c = map(int, sys.stdin.readline().split())
        maps[s].append((e, c))

    s_city, e_city = map(int, sys.stdin.readline().split())

    print(dijkstra())
