import sys
# from collections import deque
import heapq

si = sys.stdin.readline


def main():
    [n, m] = [int(e) for e in si().split()]
    big = 1000000000
    graph = dict()
    pq = []
    # be careful about making the same object in a list
    # islands = [[0, False]]*(n+1)
    islands = [[0, False] for _ in range(n+1)]

    for _ in range(m):
        [a, b, c] = [int(e) for e in si().split()]
        if a not in graph:
            graph[a] = dict()
        if b not in graph:
            graph[b] = dict()
        if b not in graph[a]:
            graph[a][b] = c
        else:
            if c > graph[a][b]:
                graph[a][b] = c
        if a not in graph[b]:
            graph[b][a] = c
        else:
            if c > graph[b][a]:
                graph[b][a] = c

    [s, g] = [int(e) for e in si().split()]

    islands[s][0] = -1*big
    heapq.heappush(pq, [-1*big, s])
    qs = 1
    while qs > 0:
        currIsland = pq[0]
        heapq.heappop(pq)
        qs -= 1
        cost, curr = -1*currIsland[0], currIsland[1]
        if islands[curr][1]:
            continue
        islands[curr][1] = True

        for dest in graph[curr]:
            if dest != curr:
                weight = min(cost, graph[curr][dest])
                if islands[dest][0] < weight:
                    islands[dest][0] = weight
                    heapq.heappush(pq, [-1*weight, dest])
                    qs += 1

    print(islands[g][0])


if __name__ == '__main__':
    main()
