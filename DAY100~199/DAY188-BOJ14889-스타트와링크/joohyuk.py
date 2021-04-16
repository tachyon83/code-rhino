import sys
from itertools import combinations as cb
si = sys.stdin.readline


def main():
    n = int(si())
    nn = n//2
    synergy = []
    for _ in range(n):
        l = [int(e) for e in si().split()]
        synergy.append(l)

    members = [i+1 for i in range(n)]
    cases = cb(members, nn)
    md = 10000
    for c in cases:
        cl = list(c)
        cs, ol = set(cl), []

        for member in members:
            if member not in cs:
                ol.append(member)

        t1, t2 = 0, 0
        for i in range(nn-1):
            for j in range(i+1, nn):
                t1 += synergy[cl[i]-1][cl[j]-1]
                t1 += synergy[cl[j]-1][cl[i]-1]
        for i in range(nn-1):
            for j in range(i+1, nn):
                t2 += synergy[ol[i]-1][ol[j]-1]
                t2 += synergy[ol[j]-1][ol[i]-1]
        md = min(md, abs(t1-t2))
    print(md)


if __name__ == '__main__':
    main()
