import sys
input = sys.stdin.readline

N, K = map(int, input().split())
temp = list(map(int, input().split()))

ret = sum(temp[:K])
cur = ret
for i in range(K, N):
    cur += temp[i] - temp[i-K]
    if ret < cur:
        ret = cur
print(ret)
