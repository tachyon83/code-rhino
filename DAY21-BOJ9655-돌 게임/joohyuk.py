n, stones, dp = int(input()), [1, 3], [0 for _ in range(1000+1)]
for i in range(n+1):
    flag = False
    for stone in stones:
        if i-stone < 0:
            continue
        if not (i-stone) or dp[i-stone]:
            flag = True
            break
    if not flag:
        dp[i] = 1
if dp[n]:
    print('CY')
else:
    print('SK')
