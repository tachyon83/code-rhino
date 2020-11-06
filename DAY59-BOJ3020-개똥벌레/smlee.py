import sys
input=sys.stdin.readline
n, h = map(int, input().split())
wall = [0] * h

for i in range(n // 2):
    wall[int(input())] -= 1
    wall[h - int(input())] += 1

min, cnt = n//2, 0
h2 = n//2

for i in wall:
    h2 += i
    if h2 < min:
        min = h2
        cnt = 1
    elif h2 == min:
        cnt += 1
      
print(min, cnt)
