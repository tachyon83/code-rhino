from bisect import bisect_left
import sys
input = sys.stdin.readline

N, H = map(int, input().split())
evens, odds = [], []
for i in range(N):
    if i%2:
        odds.append(int(input()))
    else:
        evens.append(int(input()))
        
evens.sort()
odds.sort()
MIN = float('inf')
CNT = 1

for i in range(1, H+1):
    e = bisect_left(evens, i)
    o = bisect_left(odds, H -i+1)
    ret = N//2-e + N//2-o
    if ret < MIN:
        MIN = ret
        CNT = 1
    elif ret == MIN:
        CNT += 1
    
print(MIN)
print(CNT)
