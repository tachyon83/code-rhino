import sys
si = sys.stdin.readline

dp = [[0 for _ in range(51)]for _ in range(51)]
score = [0 for _ in range(51)]

def main():
    n = int(si())
    while True:
        a, b = [int(e) for e in si().split()]
        dp[a][b] = 1
        dp[b][a] = 1
        if a == -1:
            break

    for k in range(1, n+1):
        for i in range(1, n+1):
            if k == i:
                continue
            if not dp[i][k]:
                continue
            for j in range(1, n+1):
                if j == k or j == i:
                    continue
                if not dp[k][j]:
                    continue
                if not dp[i][j] or dp[i][j] > dp[i][k]+dp[k][j]:
                    dp[i][j] = dp[i][k]+dp[k][j]

    mn, cnt, ans = 100, 0, []
    for i in range(1, n+1):
        mx = max(dp[i])
        mn = min(mn, mx)
        score[i] = mx

    for i in range(1, n+1):
        if score[i] == mn:
            cnt += 1
            ans.append(i)

    print(mn, cnt, sep=' ')
    for e in ans:
        print(e, end=' ')

if __name__ == '__main__':
    main()
