import sys
si = sys.stdin.readline


def main():
    n, k = [int(e) for e in si().split()]
    l = [int(e) for e in si().split()]
    s = 0
    for i in range(k):
        s += l[i]
    mx = s
    for i in range(k, n):
        s -= l[i-k]
        s += l[i]
        mx = max(mx, s)
    print(mx)


if __name__ == '__main__':
    main()
