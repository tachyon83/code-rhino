import sys
from heapq import heappush, heappop

def dijkstra(s):
    heap = []
    heappush(heap, (0, s))
    dis = [sys.maxsize] * (v_num+1)
    dis[s] = 0

    while heap:
        cost, idx = heappop(heap)
        for end, cost_ in v_info[idx]:
            if dis[end] > cost + cost_:
                dis[end] = cost + cost_
                heappush(heap, (cost + cost_, end))
    return dis
if __name__ == "__main__":
    v_num = int(sys.stdin.readline())
    v_info = [[] for _ in range(v_num+1)]
    for _ in range(v_num):
        v = list(map(int, sys.stdin.readline().split()))
        for i in range(1, len(v), 2):
            if v[i] != -1:
                v_info[v[0]].append([v[i], v[i+1]])

    ans = dijkstra(1)

    print(max((dijkstra(ans.index(max(ans[1:])))[1:])))
