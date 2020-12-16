def func(lst):
    dx, dy = [0, -1, 0, 1, 0], [0, 0, -1, 0, 1]
    ck = []
    result = 0

    for flower in lst:
        x = flower // N
        y = flower % N

        if x==0 or x==N-1 or y==0 or y==N-1:
            return 10000

        for i in range(5):
            ck.append((x+dx[i], y+dy[i]))
            result += pot[x+dx[i]][y+dy[i]]
            
    if len(set(ck)) == 15:
        return result
    return 10000

N = int(input())
pot = [list(map(int, input().split())) for _ in range(N)]

price = 10000
for i in range(N*N):
    for j in range(N*N):
        for k in range(N*N):
            lst = [i, j, k]
            price = min(price, func(lst))
print(price)
