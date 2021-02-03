import sys
import heapq
si = sys.stdin.readline

n = int(si())
pq1, pq2 = [], []
while n:
    n -= 1
    c = int(si())
    if not len(pq1) or c < -pq1[0]:
        heapq.heappush(pq1, -c)
    else:
        heapq.heappush(pq2, c)

    if len(pq2) > len(pq1):
        heapq.heappush(pq1, -heapq.heappop(pq2))
    elif len(pq1) > len(pq2)+1:
        heapq.heappush(pq2, -heapq.heappop(pq1))
    print(-pq1[0])
