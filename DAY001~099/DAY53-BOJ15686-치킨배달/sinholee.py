def choose_ck_m(depth, temp, idx):
    global m
    if depth == m:
        ck_able.append(temp)
        return
    for i in range(idx+1, len(chickens)):
        choose_ck_m(depth+1, temp + [chickens[i]], i)

n, m = map(int, input().split())

mat = [list(map(int, input().split())) for _ in range(n)]
houses = []
chickens = []
for i in range(n):
    for j in range(n):
        if mat[i][j] == 1:
            houses.append((i, j))
        if mat[i][j] == 2:
            chickens.append((i, j))

ck_able = []
visited = [False] * len(chickens)
for i in range(len(chickens)-m+1):
    choose_ck_m(1, [chickens[i]], i)
ans = 999999999999
for set_of_ck in ck_able:
    sub_res = 0
    for i, j in houses:
        sub_min = 9999999
        for y, x in set_of_ck:  # 치킨집 좌표
            distance = abs(i - y) + abs(j - x)
            if sub_min > distance:
                sub_min = distance
        sub_res += sub_min
    if ans > sub_res:
        ans = sub_res
print(ans)
