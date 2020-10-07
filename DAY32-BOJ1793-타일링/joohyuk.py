import sys
dp = [1 for _ in range(250+1)]
for i in range(2, 250+1):
    dp[i] = 2*dp[i-2]+dp[i-1]
for value in sys.stdin:
    print(dp[int(value)])
