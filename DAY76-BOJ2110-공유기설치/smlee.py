import sys

input = sys.stdin.readline

n, c = map(int, input().split())
house = []

for i in range(n) :
  house.append(int(input()))

house.sort()

min_gap = house[1] - house[0]
max_gap = house[-1] - house[0]
result = 0

while (min_gap <= max_gap):
    gap = (min_gap + max_gap) // 2
    value = house[0]
    cnt = 1
    for i in range(1, len(house)):
        if house[i] >= value + gap:
            value = house[i]
            cnt += 1
    if cnt >= c :
        min_gap = gap + 1
        result = gap
    else:
        max_gap = gap - 1

print(result)
