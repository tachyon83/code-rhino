import sys
#sys.stdin = open("input.txt", "r")
N = int(sys.stdin.readline())
prices = [list(map(int, input().split())) for _ in range(N)]
result = 10000
# 정지,동서남북
dx = [0,0,0,1,-1]
dy = [0,1,-1,0,0]

def get_min_price(flowers):
    result = 0
    total_price = 0
    flower_collision = set()
    for flower in flowers:
        x,y = divmod(flower, N)
        if 0 < x < N - 1 and 0 < y < N - 1:
            for i in range(5):
                nx = x + dx[i]
                ny = y + dy[i]
                total_price += prices[nx][ny]
                flower_collision.add((nx,ny))
        else:
            return 10000
    if len(flower_collision) == 15:
        return total_price
    else:
        return 10000

for i in range(N*N):
    for j in range(N*N):
        for k in range(N*N):
            result = min(result, get_min_price([i,j,k]))
print(result)
