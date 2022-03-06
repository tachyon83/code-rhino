# 용사의 체력을 이분탐색으로 찾아내기

import sys
from math import ceil
from copy import deepcopy

n, a = map(int, sys.stdin.readline().split())
li = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

lo = 0
hi = sys.maxsize
mid = (lo + hi) // 2
chk = False

while lo <= hi:
    # 루프 내내 변화하는 체력과 공격력을 deepcopy로 완전히 복사
    hp = deepcopy(mid)
    atk = deepcopy(a)
    chk = False
    for i in range(n):
        # 쿼리 첫째 항이 1일 때, 몬스터 출현
        if li[i][0] == 1:
            # 몬스터의 체력은 상관없고, 몬스터와 전투 시 깎이는 체력만 중요함
            hp -= li[i][1] * ceil((li[i][2] / atk) - 1)
            # 전투 후 제력이 마이너스일 시 (죽었을 시) 루프 탈출
            if hp <= 0:
                chk = True
                break
        # 쿼리 첫째 항이 2일 때, 포션 출현
        elif li[i][0] == 2:
            # 공격력과, 체력 업 (체력의 경우 상한선 존재)
            atk += li[i][1]
            hp = min(mid, hp + li[i][2])
    # 용사가 도중에 죽었으면 초기 체력을 올려서 재탐색
    if chk:
        lo = mid + 1
        mid = (lo + hi) // 2
    # 안 죽고 끝까지 돌았으면 초기 체력을 낮춰서 재탐색
    else:
        hi = mid - 1
        mid = (lo + hi) // 2

print(lo)
