import sys
si = sys.stdin.readline


def main():
    [n, c] = [int(e) for e in si().split()]
    coords = []
    for _ in range(n):
        coords.append(int(si()))
    coords.sort()

    s, e = 1, 10**9
    while s != e:
        mid, cnt, prev = (s+e)//2, 1, coords[0]
        for elem in coords:
            if elem-prev >= mid:
                cnt += 1
                prev = elem
        if cnt >= c:
            s = mid+1
        else:
            e = mid
    print(s-1)


if __name__ == '__main__':
    main()
