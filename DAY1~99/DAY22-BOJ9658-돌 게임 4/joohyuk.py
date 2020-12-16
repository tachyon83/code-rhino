n, stones, dp = int(input()), [1, 3, 4], [0 for _ in range(1000+1)]
for i in range(n+1):
    for stone in stones:
        if i-stone <= 0:
            break
        if not dp[i-stone]:
            dp[i] = 1
            break
if dp[n]:
    print('SK')
else:
    print('CY')
