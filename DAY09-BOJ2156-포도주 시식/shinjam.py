N = int(input())
podo = [0, 0] + [int(input()) for _ in range(N)]
dp = [0, 0, podo[2]]
for i in range(3, N + 2):
    ret = [
        dp[i - 1], 
        dp[i - 3] + podo[i - 1] + podo[i],
        dp[i - 2] + podo[i]
    ]
    dp.append(max(ret))

print(dp[N+1])
