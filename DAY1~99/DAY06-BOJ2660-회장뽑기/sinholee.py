n = int(input())

mat = [[99] * (n+1) for _ in range(n+1)]

while True:
    a, b = map(int, input().split())
    if a == -1 and b == -1:
        break
    mat[a][b] = 1
    mat[b][a] = 1


for k in range(1, n+1):
    for i in range(1, n+1):
        if k == i:
            continue
        for j in range(1, n+1):
            if k == j or i == j:
                continue
            if mat[i][k] and mat[k][j]:
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j])


res = []
for i in range(n+1):
    temp = 0
    for j in range(1, n+1):
        if mat[i][j] == 99:
            continue
        temp = max(temp, mat[i][j])
    res.append(temp)
min_value = min(res[1:])
cnt = 0
ans = ""
for i in range(1, n+1):
    if res[i] == min_value:
        cnt += 1
        ans += (str(i) + " ")
print(min_value, cnt)
print(ans)