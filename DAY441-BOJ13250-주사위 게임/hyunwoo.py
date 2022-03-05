'''
dp 문제

기댓값 = sum(각 사건이 일어날 확률 * 그 확률에 대응되는 사건의 값)
    = (각 경우의 수에 대한 사건의 합) / (전체 경우의 수)
'''

# 바텀업 dp 구현
import sys

# dp[n] : n개의 사탕을 받기 위해 던져야 하는 주사위 횟수의 기대값
dp = [0 for _ in range(1000001)]

for i in range(1, 1000001):
    # 인덱스 i에 대해 기대값 초기값을 0으로 설정하고, 
    # i-6 ~ i-1 번째 인덱스의 dp를 확인하며 갱신
    exp_value = 0
    for j in range(1, 7):
        if i - j < 0:
            exp_value += 1 / 6
        else:
            exp_value += (dp[i - j] + 1) / 6
    dp[i] = exp_value
    
n = int(sys.stdin.readline())

print(dp[n])


# # 탑다운 dp 구현
# import sys
# sys.setrecursionlimit(10000)

# li = [-1 for _ in range(1000001)]
# n = int(sys.stdin.readline())

# # dp(n) : n개의 사탕을 받기 위해 던져야 하는 주사위 횟수의 기대값
# def dp(n):
#     # n이 음수일 시, li[n]이 갱신이 안 되었을 시 즉시 탈출
#     if n <= 0 : return 0
#     if li[n] != -1 : return li[n]

#     # 기대값 계산
#     li[n] = 0
#     for i in range(1, 7):
#         li[n] += (dp(n-i) + 1) / 6
#     return li[n]

# print(dp(n))
