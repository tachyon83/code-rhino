import heapq
n = int(input())
hq = []
for _ in range(n):
    heapq.heappush(hq, int(input()))
cnt = 0
res = 0
while cnt < n-1:
    a = heapq.heappop(hq) 
    b = heapq.heappop(hq) 
    heapq.heappush(hq, a+b)
    res += a+b
    cnt += 1
print(res)  
