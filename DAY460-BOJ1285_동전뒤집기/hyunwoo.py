import sys

n = int(sys.stdin.readline())
coin = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
ans = sys.maxsize

for bit in range(1 << n):
    temp = [coin[i][:] for i in range(n)]
    for i in range(n):
        if bit & (1 << i):
            for j in range(n):
                if temp[i][j] == 'H':
                    temp[i][j] = 'T'
                else:
                    temp[i][j] = 'H'
    total = 0
    for i in range(n):
        count = 0
        for j in range(n):
            if temp[j][i] == 'T':
                count += 1
        total += min(count, n-count)
    ans = min(ans, total)

print(ans)
