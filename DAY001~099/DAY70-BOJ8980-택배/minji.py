import sys

def sol(limit):
    lst.sort(key=lambda x:x[1])
    ans = 0
    weight = [0] * (n+1)

    for s, e, w in lst:
        l = limit - max(weight[s:e])
        tmp = w if w <= l else l
        ans += tmp
        for i in range(s, e):
            weight[i] += tmp
    print(ans)

if __name__ == "__main__":
    n, c = map(int, sys.stdin.readline().split())
    m = int(sys.stdin.readline())
    lst = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]

    sol(c)
