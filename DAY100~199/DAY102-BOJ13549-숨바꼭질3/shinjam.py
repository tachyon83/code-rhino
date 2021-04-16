from heapq import heappush, heappop
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
MAX = 100_001
visited = [False]*MAX
visited[N] = True

def bfs():
    queue = [(0, N)]
    while queue:
        time, x = heappop(queue)
        if x==K:
            return time
        if x*2<MAX and not visited[x*2]:
            heappush(queue, (time, x*2))
            visited[x*2]=True
        if x+1<MAX and not visited[x+1]:
            heappush(queue, (time+1, x+1))
            visited[x+1]=True
        if x-1>=0 and not visited[x-1]:
            heappush(queue, (time+1, x-1))
            visited[x-1]=True
if N >= K:
    print(abs(N-K))
else:
    print(bfs())
