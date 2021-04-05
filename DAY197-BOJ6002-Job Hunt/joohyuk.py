import sys
si = sys.stdin.readline

d, p, c, f, s = [int(e) for e in si().split()]
g, earnings = [[] for _ in range(c+1)], [0 for _ in range(c+1)]

while p:
    p -= 1
    a, b = [int(e) for e in si().split()]
    g[a].append([b, 0])
while f:
    f -= 1
    a, b, w = [int(e) for e in si().split()]
    g[a].append([b, w])

earnings[s], flag = d, False
for i in range(c):
    for city in range(c+1):
        for np in g[city]:
            if earnings[np[0]] < d-np[1]+earnings[city]:
                earnings[np[0]] = d-np[1]+earnings[city]
                if i == c-1:
                    flag = True

if flag:
    print(-1)
else:
    print(max(earnings))
