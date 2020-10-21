import sys
from itertools import combinations

input = sys.stdin.readline

N = int(input())
BOARD = [list(map(int,input().split())) for _ in range(N)]

# 꽃술 완전 탐색하여 꽃 세개 케이스 탐색
# 상하좌우 꽃잎

def solve(nums):
    pos = (divmod(num, N) for num in nums)
    ck = set()
    cost = 0
    for x, y in pos:
        if not all([0<x<N-1, 0<y<N-1]):
            return float('inf')
        
        for v in range(5):
            nx, ny = x + dx[v], y + dy[v]
            if (nx, ny) in ck:
                return float('inf')
            ck.add((nx, ny))
            cost += BOARD[ny][nx]

    return cost
    
dx, dy = (0, 1, 0, -1, 0), (0, 0, 1, 0, -1)

cands = combinations(range(N**2), 3)
MAX = float('inf')
for cand in cands:
    ret = solve(cand)
    if ret < MAX:
        MAX = ret
print(MAX)
