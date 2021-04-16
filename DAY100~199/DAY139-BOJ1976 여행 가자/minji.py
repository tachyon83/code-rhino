import sys

def find_parent(x):
    if citys[x] != x:
        citys[x] = find_parent(citys[x])
    return citys[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        citys[b] = a
    else:
        citys[a] = b

if __name__ == "__main__":

    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())

    citys = [i for i in range(n+1)]

    for i in range(n):
        maps = list(map(int, sys.stdin.readline().split()))
        for j in range(n):
            if maps[j]:
                union_parent(i+1, j+1)

    plan = list(map(int, sys.stdin.readline().split()))

    res = "YES"
    before = 0
    for i, city in enumerate(plan):
        fc = find_parent(city)
        if not i:
            before = fc
            continue
        if before != find_parent(city):
            res = "NO"
            break
        before = fc
    print(res)
