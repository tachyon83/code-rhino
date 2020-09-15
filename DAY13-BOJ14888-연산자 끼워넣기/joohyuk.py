import sys
from itertools import permutations as pm
si = sys.stdin.readline


def main():
    n = int(si())
    l = [int(e) for e in si().split()]
    op = [int(e) for e in si().split()]
    opl = []
    for i in range(4):
        if i == 0:
            o = 1
        elif i == 1:
            o = 2
        elif i == 2:
            o = 3
        else:
            o = 4
        for _ in range(op[i]):
            opl.append(o)

    p = pm(opl, n-1)
    mx, mn = (-1)*(1+int(1e9)), 1+int(1e9)
    for e in p:
        idx = 0
        tot = l[idx]
        e = list(e)
        # print(e)
        for ee in e:
            idx += 1
            if ee == 1:
                tot += l[idx]
            elif ee == 2:
                tot -= l[idx]
            elif ee == 3:
                tot *= l[idx]
            else:
                if tot < 0:
                    tot = (tot*(-1)//l[idx])*(-1)
                else:
                    tot //= l[idx]
        # print(tot)
        if tot < mn:
            mn = tot
        if tot > mx:
            mx = tot

    print(mx)
    print(mn)


if __name__ == '__main__':
    main()
