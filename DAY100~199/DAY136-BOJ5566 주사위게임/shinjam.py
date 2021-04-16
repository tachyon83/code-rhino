N, M = map(int, input().split())
BOARD = list(int(input()) for _ in range(N))
DICES = list(int(input()) for _ in range(M))
    
cur = 0
for n in range(M):
    cur += DICES[n]
    if cur >= N-1:
        break
    cur += BOARD[cur]
    if cur >= N-1:
        break
print(n+1)
