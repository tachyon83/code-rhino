'''
하... 갓원우님꺼 복붙수준으로 풀었네요..
타키온님꺼는 감히 엄두를 못냄
'''

n = int(input())

dp = [[[0] * (1<<10) for _ in range(10)] for _ in range(n+1)]
for i in range(1, 10):
    dp[1][i][1<<i] = 1
for i in range(2, n+1):
    for j in range(10):
        for b in range(1<<10):
            if j == 0:
                dp[i][j][b | 1 << j] = dp[i-1][1][b] + dp[i][j][b | 1 << j]
            elif j == 9:
                dp[i][j][b | 1 << j] = dp[i-1][8][b] +dp[i][j][b | 1 << j]     
            else:
                dp[i][j][b | 1 << j] = dp[i-1][j-1][b] + dp[i][j][b | 1 << j] 
                dp[i][j][b | 1 << j] = dp[i-1][j+1][b] + dp[i][j][b | 1 << j]

res = 0
for j in range(10):
    res += dp[n][j][(1<<10)-1]

print(res % 1000000000)
