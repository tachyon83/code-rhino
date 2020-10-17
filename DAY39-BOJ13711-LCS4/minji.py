import sys
import bisect

def sol():
    res = [a[0]]
    for v in a[1:]:
        if v > res[-1]:
            res.append(v)
        else:
            idx = bisect.bisect_left(res, v)
            res[idx] = v
    print(len(res))

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    b = list(map(int, sys.stdin.readline().split()))
    lcs = [0 for _ in range(n+1)]

    for i in range(n):
        lcs[b[i]] = i
    for i in range(n):
        a[i] = lcs[a[i]]

    sol()
