N = int(input())
DP = [list(map(int, input().split())) for _ in range(N)]

def check(DP, N):
    ret = 0
    for idx in range(N**2):
        i, j = divmod(idx, N)
        if i >= j:
            continue
        for k in range(N):
            if k!=i and k!=j:
                cur, comp = DP[i][j], DP[i][k] + DP[k][j]
                if cur > comp:
                    return -1
                if cur == comp:
                    break
        else:
            ret += DP[i][j]

    return ret


print(check(DP, N))
