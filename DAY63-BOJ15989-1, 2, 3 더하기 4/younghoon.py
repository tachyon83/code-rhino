import sys

#sys.stdin = open('input.txt', 'r')
T = int(sys.stdin.readline())
dp = [1] * 10001


for i in range(2, 10001):
    dp[i] += dp[i - 2]


for i in range(3, 10001):
    dp[i] += dp[i - 3]

for _ in range(T):
    n = int(sys.stdin.readline())
    print(dp[n])

