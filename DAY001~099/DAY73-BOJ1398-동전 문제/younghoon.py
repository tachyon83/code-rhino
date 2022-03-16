import sys
#sys.stdin = open('input.txt', 'r')

coin = [1, 10, 25]
dp = [0] * 100
for i in range(1, len(dp)):
    dp[i] = sys.maxsize
    for j in range(len(coin)):
        if (i - coin[j]) >= 0:
            dp[i] = min(dp[i], dp[i-coin[j]] + 1)


N = int(sys.stdin.readline())
for _ in range(N):
    n = int(sys.stdin.readline())
    count = 0
    while n > 0:
        partition_100 = n % 100
        count += dp[partition_100]
        n = int(n/100)
    print(count)
