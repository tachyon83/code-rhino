import sys

def sol(total):
    cnt = 0
    while total > 0:
        a = total % 100
        cnt += dp[a]
        total //= 100
    return cnt

if __name__ == "__main__":
    t = int(sys.stdin.readline())
    coin = [1, 10, 25]
    dp = [0] * 100
    for i in range(1, 100):
        dp[i] = 0x7fffffff
        for j in coin:
            if i - j >= 0:
                dp[i] = min(dp[i], dp[i-j]+1)

    for i in range(t):
        total = int(sys.stdin.readline())
        print(sol(total))
