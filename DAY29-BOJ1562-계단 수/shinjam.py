from collections import defaultdict

N = int(input())

DP = {i:defaultdict(int) for i in range(10)} # 마지막 숫자의 비트마스크: 개수
for i in range(1, 10):
    DP[i][1<<i] = 1

for n in range(N-1):
    tmp = {i:defaultdict(int) for i in range(10)}
    for i in range(10):
        for key, val in DP[i].items():
            if i < 9:
                tmp[i + 1][key | 1<<i] = tmp[i + 1][key | 1<<i] + val
            if 0 < i:
                tmp[i - 1][key | 1<<i] = tmp[i - 1][key | 1<<i] + val

    DP.update(tmp)
    
ret = 0
for i in range(10):
    ret += DP[i][1023]
print(ret)

# 왜 안되는걸까요 ㅜㅠ
