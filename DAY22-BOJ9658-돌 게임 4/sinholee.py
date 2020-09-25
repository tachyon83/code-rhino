n = int(input())

dp = [0] * (n+5)
dp[1] = 0
dp[2] = 1
dp[3] = 0
dp[4] = 1

for i in range(5, n+1):
    if dp[i-1] ==0 or  dp[i-3] == 0  or dp[i-4] == 0:
        dp[i] = 1
    else:
        dp[i] = 0
print('SK' if dp[n] else 'CY')

