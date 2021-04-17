import sys

n = int(sys.stdin.readline())
distance = [[sys.maxsize for _ in range(n + 1)] for _ in range(n + 1)]

for i in range(1, n+1):
    distance[i][i] = 0

while True:
    a, b = map(int, sys.stdin.readline().split())
    if a == -1 and b == -1:
        break
    distance[a][b] = 1
    distance[b][a] = 1

for k in range(1, n + 1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if distance[i][j] > distance[i][k] + distance[k][j]:
                distance[i][j] = distance[i][k] + distance[k][j]

ans = sys.maxsize
ans_list = []
tmp_list = []

for i in range(1, n+1):
    ans = min(ans, max(distance[i][1:]))
for i in range(1, n+1):
    if ans == max(distance[i][1:]):
        ans_list.append(i)

print(ans, len(ans_list))
print(' '.join(map(str, ans_list)))

