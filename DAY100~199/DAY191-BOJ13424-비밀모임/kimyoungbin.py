import sys
T = int(sys.stdin.readline())
for _ in range(T):
    N, M = map(int, sys.stdin.readline().split())
    g =[[sys.maxsize for _ in range(N + 1)] for _ in range(N + 1)]
    for i in range(1,N+1):
        g[i][i] = 0
    for _ in range(M):
        a, b, c = map(int, sys.stdin.readline().split())
        g[a][b] = c
        g[b][a] = c
    K = int(sys.stdin.readline())
    friends = sys.stdin.readline().split()
    for mid in range(1, N + 1):
        for i in range(1, N + 1):
            for j in range(1, N + 1):
                if g[i][j] > g[i][mid] + g[mid][j]:
                    g[i][j] = g[i][mid] + g[mid][j]
    ans = 0
    ans_sum = sys.maxsize
    for i in range(1, N+1):
        sum = 0
        for f in friends:
            sum += g[i][int(f)]
        if ans_sum > sum:
            ans_sum = sum
            ans = i
    print(ans)



