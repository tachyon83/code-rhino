import sys

def sol():
    for i in range(1, 10): #0을 제외한 1-9까지 1로 초기화, 0은 시작 숫자될수 없음
        dp[1][i][1 << i] = 1

    for i in range(2, n+1):
        for j in range(10):
            a = 1<<j
            for k in range(1024):
                if j == 0:
                    dp[i][j][k|a] += dp[i-1][j+1][k]
                elif j == 9:
                    dp[i][j][k|a] += dp[i-1][j-1][k]
                else:
                    dp[i][j][k|a] += (dp[i-1][j+1][k] + dp[i-1][j-1][k])
    ans = 0
    for k in range(10):
        ans = (ans + dp[n][k][1023]) % 1000000000 #n자리 숫자중, k로 끝나고 1023에 마킹 된 숫자
    print(ans)


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    dp = [[[0 for _ in range(1024)] for _ in range(10)] for _ in range(n+1)]

    sol()
