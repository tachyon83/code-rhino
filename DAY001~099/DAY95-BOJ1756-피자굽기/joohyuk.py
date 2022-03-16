import sys
import heapq
si = sys.stdin.readline

d, n = [int(e) for e in si().split()]
d -= 1
oven, pq = [int(e) for e in si().split()], []
doughs = [int(e) for e in si().split()]
for i, o in enumerate(oven):
    heapq.heappush(pq, [o, -i])

for dough in doughs:
    flag = False
    while pq and (-pq[0][1] > d or dough > pq[0][0]):
        if dough > pq[0][0]:
            d = -pq[0][1]
        heapq.heappop(pq)
    if pq and dough <= pq[0][0]:
        flag = True
        d -= 1
    else:
        break

if flag:
    print(d+1)
else:
    print(0)
