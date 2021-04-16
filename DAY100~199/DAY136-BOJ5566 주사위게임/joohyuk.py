import sys
si = sys.stdin.readline

n, m = [int(e) for e in si().split()]
board, curr = [0 for _ in range(n+1)], 1
for i in range(1, n+1):board[i] = int(si())
for i in range(m):
    dice = int(si())
    curr += dice
    if curr>n:curr=n
    curr += board[curr]
    if curr >= n:
        print(i+1)
        break
