import sys
si = sys.stdin.readline

h, w, x, y = [int(e) for e in si().split()]
A, B = [[0 for _ in range(w)]for _ in range(h)], []

for _ in range(h+x):
    B.append([int(e) for e in si().split()])

for i in range(x):
    for j in range(w):
        A[i][j] = B[i][j]
for i in range(x, h+x):
    for j, e in enumerate(B[i]):
        if i < h and j < y:
            A[i][j] = B[i][j]
        elif i < h and y <= j < w:
            A[i][j] = B[i][j]-A[i-x][j-y]

for e in A:
    print(*e)
