from collections import defaultdict
import sys
input = sys.stdin.readline

# 맵크기, 나무 수, 년도 횟수
N, M, K = map(int, input().split())
# 영양분 표
A = [list(map(int, input().split())) for _ in range(N)]
# 영양분 상태 초기화
current_A = [[5]*(N) for _ in range(N)]
# 나무
trees = defaultdict(list)
for _ in range(M):
    x, y, z = map(int, input().split())
    trees[(x-1, y-1)].append(z)
# 인접 방향
vectors = (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)


# 년도 회전
for _ in range(K):
    alives = defaultdict(list)
    for idx in range(N**2):
        x, y = idx//N, idx%N
        if not trees[(x, y)]:
            current_A[x][y] += A[x][y]
            continue
        trees[(x,y)].sort(reverse=True)
        ages = trees[(x,y)]
        new_nutrients = 0
        while ages:
            age = ages.pop()
            new_age = age+1
            if current_A[x][y] >= age:
                alives[(x,y)].append(new_age)
                current_A[x][y] -= age
                if new_age%5==0:
                    for v in vectors:
                        nx, ny = x+v[0], y+v[1]
                        if 0 <= nx < N and 0 <= ny < N:
                            alives[(nx, ny)].append(1)
            else:
                new_nutrients += age//2
        current_A[x][y] += A[x][y] + new_nutrients
    trees = alives


ans = 0
for ages in trees.values():
    ans += len(ages)
print(ans)
