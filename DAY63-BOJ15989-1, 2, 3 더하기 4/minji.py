import sys

t = int(sys.stdin.readline())
dp = [1 for i in range(10001)]
lst = []

for _ in range(t):
    lst.append(int(sys.stdin.readline()))

for i in range(2, 10001):
    dp[i] += dp[i - 2]
for i in range(3, 10001):
    dp[i] += dp[i - 3]
    
for i in lst:
    print(dp[i])
