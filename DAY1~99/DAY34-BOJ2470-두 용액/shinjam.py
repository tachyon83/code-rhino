from math import inf
import sys
input = sys.stdin.readline

N = int(input())
samples = list(map(int, input().split()))
samples.sort(key=lambda x: abs(x))

cret = inf
ret = []
for i in range(N-1):
    cmp = abs(samples[i] + samples[i+1])
    if cmp < cret:
        cret = cmp
        ret = [samples[i], samples[i+1]]
print(*sorted(ret))
