import math
input = __import__('sys').stdin.readline

N, curA = map(int, input().split())
maxHp = 0
curHp = 0

for _ in range(N):
    op, *arr = map(int, input().split())
    if op == 1:
        dmg = (math.ceil(arr[1] / curA) - 1) * arr[0]
        if dmg > curHp:
            maxHp += dmg - curHp
            curHp = 0
        else:
            curHp -= dmg
    else:
        curA += arr[0]
        if maxHp >= curHp + arr[1]:
            curHp += arr[1]
        else:
            curHp = maxHp

print(maxHp + 1)
