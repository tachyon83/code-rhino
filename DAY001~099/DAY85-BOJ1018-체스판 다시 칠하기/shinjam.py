import sys
input = sys.stdin.readline
N, M = map(int, input().split())
A = [input() for _ in range(N)]
ans = 64


def check(i, j):
    cnt = 0
    for x in range(8):
        for y in range(8):
            cnt += (A[i + x][j + y] == 'W') ^ (x + y) % 2
    return min(cnt, 64 - cnt)


for i in range(N - 8 + 1):
    for j in range(M - 8 + 1):
        # 8 by 8을 자를때 시작 인덱스를 넘겨줌
        ans = min(check(i, j), ans)

print(ans)
