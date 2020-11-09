t = int(input())
dp = [[0]*3 for _ in range(10001)]
dp[0] = [1, 0, 0]
dp[1] = [1, 1, 0]
dp[2] = [1, 1, 1]

for _ in range(t) :
  n = int(input())
  if n <= 3 :
    print(sum(dp[n-1]))
    continue
  for i in range(3, n+1) :
    dp[i][0] = dp[i-1][0]
    dp[i][1] = dp[i-2][0] + dp[i-2][1]
    dp[i][2]= dp[i-3][2]+ dp[i-3][1]+ dp[i-3][0]
  
  print(sum(dp[n-1]))
