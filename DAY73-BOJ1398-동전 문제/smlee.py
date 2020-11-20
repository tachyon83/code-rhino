coin = [1, 10, 25]
dp = [0] * 100

for i in range(1, len(dp)):
    dp[i] = 0x7f7f7f7f
    for j in range(len(coin)):
        if (i - coin[j]) >= 0:
            dp[i] = min(dp[i], dp[i-coin[j]] + 1)
            
t = int(input())

for i in range(t):
    n = int(input())
    coin_cnt = 0
    while n > 0:
        pt_100 = n % 100
        coin_cnt += dp[pt_100]
        n = int(n/100)
    print(coin_cnt)
