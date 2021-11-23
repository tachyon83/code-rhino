import sys
si = sys.stdin.readline


def main():
    n = int(si())
    l = [int(e) for e in si().split()]
    l = sorted(l)
    if l[0] < 0 and l[-1] <= 0:
        print(l[-2], l[-1])
        return
    if l[0] >= 0 and l[-1] > 0:
        print(l[0], l[1])
        return

    s, e, diff = 0, n-1, int(2e9+1)
    s1, s2 = l[s], l[e]
    while s < e:
        temp = l[s]+l[e]
        if abs(temp) < diff:
            diff = abs(temp)
            s1, s2 = l[s], l[e]
        if not temp:
            break
        if temp > 0:
            e -= 1
        else:
            s += 1

    print(s1, s2)


if __name__ == '__main__':
    main()
