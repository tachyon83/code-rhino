import sys
input = sys.stdin.readline

N, K = map(int, input().split())
NUMS = list(int(input()) for _ in range(N))

cnt, cur = 0, K
for num in NUMS[::-1]:
    if num <= cur:
        cnt += cur//num
        cur = cur%num
print(cnt)
