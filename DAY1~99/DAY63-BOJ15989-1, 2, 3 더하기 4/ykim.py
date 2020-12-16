import sys
input = sys.stdin.readline

t = int(input())
dp = [1 for i in range(10001)]
lst = []

for _ in range(t):
    lst.append(int(input()))

for i in range(2, 10001):
    dp[i] += dp[i - 2]
for i in range(3, 10001):
    dp[i] += dp[i - 3]
    
for i in lst:
    print(dp[i])
