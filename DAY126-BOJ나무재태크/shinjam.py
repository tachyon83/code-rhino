from collections import defaultdict

n, m, k = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
matrix = [[5]*n for _ in range(n)]
tree = [[defaultdict(int) for _ in range(n)] for _ in range(n)]
for _ in range(m):
    y, x, z = map(int, input().split())
    tree[y-1][x-1][z] += 1

d = [[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]
def solution(matrix,tree,a):
    temp = [[defaultdict(int) for _ in range(n)] for _ in range(n)]
    for y in range(n):
        for x in range(n):
            if not tree[y][x] :
                matrix[y][x] += a[y][x]
                continue
            die = 0
            spread = 0
            for age,num in sorted(tree[y][x].items()):
                cnt = matrix[y][x]//age
                if cnt >= num:
                    matrix[y][x] -= age*num
                    temp[y][x][age+1] += num
                    if (age+1) % 5 == 0:
                        spread += num
                elif 1<= cnt < num:
                    matrix[y][x] -= age*cnt
                    temp[y][x][age+1] += cnt
                    die += (age//2)*(num-cnt)
                    if (age+1) % 5 == 0:
                        spread += cnt
                else:
                    die += (age//2)*num
            if spread != 0:
                for dx,dy in d:
                    ax,ay = x+dx, y+dy
                    if 0<= ax < n and 0 <= ay < n:
                        temp[ay][ax][1] += spread
            matrix[y][x] += a[y][x] + die
    return temp

for _ in range(k):
    tree = solution(matrix,tree,a)

result = 0
for y in range(n):
    for x in range(n):
        result += sum(tree[y][x].values())
print(result)
