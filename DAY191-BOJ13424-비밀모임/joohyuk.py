import sys
si = sys.stdin.readline

t, big = int(si()), int(5e6)+1
while t:
    t -= 1
    n, m = [int(e) for e in si().split()]
    cost = [[big for _ in range(1+n)]for _ in range(n+1)]
    for i in range(1, n+1):
        cost[i][i] = 0

    while m:
        m -= 1
        a, b, c = [int(e) for e in si().split()]
        cost[a][b] = cost[b][a] = c

    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j])

    k, s, ans = int(si()), big, 0
    ppl = [int(e) for e in si().split()]
    for i in range(1, 1+n):
        tmp = 0
        for person in ppl:
            tmp += cost[person][i]
        if tmp < s:
            ans, s = i, tmp
    print(ans)
