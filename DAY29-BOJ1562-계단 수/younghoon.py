'''
다음기회에...
이해를 할수 있도록 해보겠슴니다..
'''

import sys
#sys.stdin = open("input.txt", "r")

bit = 1<<10
n = int(sys.stdin.readline())
dp = [[[0 for k in range(bit)] for i in range(10)] for j in range(101)]
for i in range(1, 10):
    dp[1][i][1<<i] = 1
for i in range(2, n + 1):
    for j in range(10):
        for k in range(bit):
            if j == 0:
                dp[i][j][k | (1<<j)] += dp[i - 1][1][k]
            elif j == 9:
                dp[i][j][k | (1<<j)] += dp[i - 1][8][k]
            else:
                dp[i][j][k | (1<<j)] += dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]

sum = 0
for i in range(10):
    sum = (sum + dp[n][i][bit-1])%1000000000;
print(sum)
