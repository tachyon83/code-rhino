N, C = map(int, input().split())
info = list(tuple(map(int, input().split())) for _ in range(int(input())))
info.sort(key=lambda x:x[1])

ans = 0
costs = [0] * (N+1)
for to, frm, cost in info:
    left = C - max(costs[to:frm])
    tmp = cost if cost <= left else left
    ans += tmp
    for i in range(to, frm):
        costs[i] += tmp
print(ans)  
