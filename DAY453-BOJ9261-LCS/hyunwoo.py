# 2차원 dp를 이용하는 문제

import sys

word1 = sys.stdin.readline().rstrip()
word2 = sys.stdin.readline().rstrip()

# dp[i][j] = word1[:i], word2[:j] 두 문자열의 LCS
dp = [[0 for _ in range(len(word2)+1)] for __ in range(len(word1)+1)]

for i in range(1, len(word1)+1):
    for j in range(1, len(word2)+1):
        # 각 문자열의 i-1, j-1번째 글자가 일치할 시 dp[i][j]는 dp[i-1][j-1] + 1이 됨
        if word1[i-1] == word2[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        # 그 외의 경우는 dp[i][j]는 dp[i][j-1], dp[i-1][j] 중 큰 값
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])

print(dp[-1][-1])
