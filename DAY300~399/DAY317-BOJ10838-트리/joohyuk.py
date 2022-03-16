import sys
si = sys.stdin.readline

n, k = [int(e) for e in si().split()]
p = [0 for _ in range(n+1)]
temp = [0 for _ in range(n+1)]
color = [0 for _ in range(n+1)]


def lca(a, b, i):
    i += int(1e5)+1
    if a == b:return a
    cnt = 0
    while a and cnt < 1000:
        temp[a] = i
        a = p[a]
        cnt += 1
    while b and temp[b] != i:b = p[b]
    return b


while k:
    k -= 1
    line = [int(e) for e in si().split()]
    if line[0] == 1:
        a, b, c = line[1], line[2], line[3]
        r = lca(a, b, k)

        while a and a != r:
            color[a] = c
            a = p[a]
        while b and b != r:
            color[b] = c
            b = p[b]

    elif line[0] == 2:
        a, b = line[1:]
        p[a] = b

    else:
        a, b = line[1:]
        cs = set()
        r = lca(a, b, k)

        while a and a != r:
            cs.add(color[a])
            a = p[a]
        while b and b != r:
            cs.add(color[b])
            b = p[b]

        print(len(cs))
