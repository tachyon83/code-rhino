import sys
from heapq import heappop, heappush
input = sys.stdin.readline

heap = sorted(int(input()) for _ in range(int(input())))

ans = 0
while len(heap) > 1:
    val = heappop(heap) + heappop(heap)
    ans += val
    heappush(heap, val)
    
print(ans)
