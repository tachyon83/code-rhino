import sys

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    tp = set(sys.stdin.readline().rstrip().split()[1:])
    party = []
    check = []

    for i in range(m):
        party.append(set(sys.stdin.readline().rstrip().split()[1:]))
        check.append(True)

    for _ in range(m): #party
        for i, p in enumerate(party):
            if tp.intersection(p):
                check[i] = False
                tp = tp.union(p)
    print check.count(True)
