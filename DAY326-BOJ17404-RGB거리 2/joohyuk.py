import heapq
import sys
si = sys.stdin.readline


def solve():
    big = 1000*1000+1
    n = int(si())
    cost = []
    for _ in range(n):
        l = [int(e) for e in si().split()]
        cost.append(l)
    if n == 2:
        cost[1][0] += min(cost[0][1], cost[0][2])
        cost[1][1] += min(cost[0][2], cost[0][0])
        cost[1][2] += min(cost[0][0], cost[0][1])
        print(min(cost[1]))
        return

    dp = [[[[0, 0], [0, 0]], [[0, 0], [0, 0]], [[0, 0], [0, 0]]]
          for _ in range(n)]
    # sc=start color

    if cost[0][1] < cost[0][2]:
        c1, c2 = cost[0][1], cost[0][2]
        sc1, sc2 = 1, 2
    else:
        c1, c2 = cost[0][2], cost[0][1]
        sc1, sc2 = 2, 1
    dp[1][0][0][0], dp[1][0][1][0] = cost[1][0]+c1, cost[1][0]+c2
    dp[1][0][0][1], dp[1][0][1][1] = sc1, sc2

    if cost[0][0] < cost[0][2]:
        c1, c2 = cost[0][0], cost[0][2]
        sc1, sc2 = 0, 2
    else:
        c1, c2 = cost[0][2], cost[0][0]
        sc1, sc2 = 2, 0
    dp[1][1][0][0], dp[1][1][1][0] = cost[1][1]+c1, cost[1][1]+c2
    dp[1][1][0][1], dp[1][1][1][1] = sc1, sc2

    if cost[0][1] < cost[0][0]:
        c1, c2 = cost[0][1], cost[0][0]
        sc1, sc2 = 1, 0
    else:
        c1, c2 = cost[0][0], cost[0][1]
        sc1, sc2 = 0, 1
    dp[1][2][0][0], dp[1][2][1][0] = cost[1][2]+c1, cost[1][2]+c2
    dp[1][2][0][1], dp[1][2][1][1] = sc1, sc2

    for i in range(2, n):
        for j in range(3):
            pq = []
            for k in range(1, 3):
                for mn in range(2):
                    heapq.heappush(pq, dp[i-1][(j+k) % 3][mn])

            dp[i][j][0] = heapq.heappop(pq)[:]
            dp[i][j][0][0] += cost[i][j]
            sc = dp[i][j][0][1]
            temp = heapq.heappop(pq)[:]
            while temp[1] == sc:
                temp = heapq.heappop(pq)[:]
            dp[i][j][1] = temp
            dp[i][j][1][0] += cost[i][j]

    m = big
    for i in range(3):
        if dp[n-1][i][0][1] != i:
            tempV = dp[n-1][i][0][0]
        else:
            tempV = dp[n-1][i][1][0]
        m = min(m, tempV)
    print(m)
    
    
solve()
