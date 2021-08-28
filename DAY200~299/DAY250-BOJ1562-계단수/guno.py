import sys
input=sys.stdin.readline

n=int(input())
dp=[[0]*1024 for _ in range(10)]

for i in range(1,10):
    dp[i][1<<i]=1

for _ in range(1,n):
    dp_next=[[0]*1024 for _ in range(10)]
    for i in range(10):
        for bit in range(1024):
            if i<9:
                dp_next[i][bit|(1<<i)]+=dp[i+1][bit]
            if i>0:
                dp_next[i][bit|(1<<i)]+=dp[i-1][bit]
            dp_next[i][bit|(1<<i)]%=1000000000
    dp=dp_next

print(sum([dp[i][1023] for i in range(10)])%1000000000)

#-----------------다른 풀이-------------------------------------
import copy
N=int(input())
dp = [[0, 0, 0, 0]] + [[1, 0, 0, 0] for i in range(8)] + [[0, 0, 1, 0]]
next_dp = [[0, 0, 0, 0] for i in range(10)]
# 한칸씩 움직이므로 0,9 만 방문했으면 모두 방문한것이다
# 0열: 0,9 모두 미방문, 1열: 0방문, 2열: 9방문, 3열: 0,9모두 방문

for n in range(1, N):
    for i in range(1, 9):
        for f in range(4):
            next_dp[i][f] = dp[i - 1][f] + dp[i + 1][f]
    for f in [0, 2]:
        next_dp[0][f | 1] = dp[1][f] + dp[1][f | 1]
    for f in [0, 1]:
        next_dp[9][f | 2] = dp[8][f] + dp[8][f | 2]
    dp=copy.deepcopy(next_dp)

print(sum([e[3] for e in dp])%10**9)
