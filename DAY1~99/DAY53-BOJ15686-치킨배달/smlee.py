from itertools import combinations
import sys

N, M = map(int,sys.stdin.readline().split())
chickenMap = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
house = []
chicken = []
min_val = float('inf')

for i in range(N):
    for j in range(N):
        if chickenMap[i][j] == 1: house.append((i, j))
        elif chickenMap[i][j] == 2: chicken.append((i, j))
 
for chk in combinations(chicken, M):
    result = 0
    for home in house:
        result += min([abs(home[0]-i[0])+abs(home[1]-i[1]) for i in chk])
        if min_val <= result : 
          break
    if result < min_val : 
      min_val = result
 
print(min_val)
