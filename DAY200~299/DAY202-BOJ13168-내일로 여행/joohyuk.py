import sys
import math
si = sys.stdin.readline

big, notDiscountables = math.inf, 'SubwayBusTaxiAirplaneKTX'
n, r = [int(e) for e in si().split()]
cities = [e for e in si().split()]
cost, cityMap = [[[math.inf, math.inf]
                  for _ in range(n)]for _ in range(n)], dict()

for i in range(n):
    cityMap[cities[i]] = i
    cost[i][i] = [0, 0]

m = int(si())
visits = [e for e in si().split()]
k = int(si())
while k:
    k -= 1
    kind, a, b, w = [e for e in si().split()]
    a, b = cityMap[a], cityMap[b]
    w = int(w)
    cost[a][b][1] = cost[b][a][1] = min(cost[a][b][1], w)
    if kind not in notDiscountables:
        if kind in 'S-TrainV-Train':
            w /= 2
        else:
            w = 0
    cost[a][b][0] = cost[b][a][0] = min(cost[a][b][0], w)

for k in range(n):
    for i in range(n):
        for j in range(n):
            cost[i][j][0] = cost[j][i][0] = min(
                cost[i][j][0], cost[i][k][0]+cost[k][j][0])
            cost[i][j][1] = cost[j][i][1] = min(
                cost[i][j][1], cost[i][k][1]+cost[k][j][1])

start, t1, t2 = cityMap[visits[0]], 0, 0
for i in range(1, m):
    nx = cityMap[visits[i]]
    t1 += cost[start][nx][0]
    t2 += cost[start][nx][1]
    start = nx

print('Yes' if t1+r < t2 else 'No')
