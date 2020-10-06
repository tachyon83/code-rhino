import sys
import operator
from itertools import permutations

def sol():
    ops = []
    ans = []
    num = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    for s in sign:
        if s == "<":
            ops.append(operator.lt)
        else:
            ops.append(operator.gt)

    for p in (permutations(num, k+1)):
        check = True
        for i in range(k):
            if not ops[i](p[i], p[i+1]):
                check = False
        if check:
            ans.append(p)

    print("".join([str(i) for i in ans[-1]]))
    print("".join([str(i) for i in ans[0]]))


if __name__ == "__main__":
    k = int(sys.stdin.readline())
    sign = sys.stdin.readline().split()

    sol()
