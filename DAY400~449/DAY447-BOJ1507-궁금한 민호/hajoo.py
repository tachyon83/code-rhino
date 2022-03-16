import copy
input = __import__('sys').stdin.readline

N = int(input())
city = [list(map(int, input().split())) for _ in range(N)]
copyCity = copy.deepcopy(city)

for k in range(N):
    for i in range(N):
        for j in range(N):
            if i == j or k == i or k == j:
                continue
            if city[i][k] + city[k][j] < city[i][j]:
                print(-1)
                exit()
            if city[i][k] + city[k][j] == city[i][j]:
                copyCity[i][j] = 0

ans = 0
for i in range(N):
    for j in range(N):
        ans += copyCity[i][j]

print(ans // 2)
