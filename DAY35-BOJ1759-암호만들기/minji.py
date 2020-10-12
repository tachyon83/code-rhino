import sys
from itertools import combinations

def sol():
    n_sp = sorted(sp)
    c_list = ['a', 'e', 'i', 'o', 'u']

    for i in combinations(n_sp, l):
        cnt = 0
        if any(c_l in i for c_l in c_list):
            for j in range(5):
                cnt += i.count(c_list[j])
            if l-cnt >= 2:
                print(''.join(i))

if __name__ == "__main__":
    l, c = map(int, sys.stdin.readline().split())
    sp = list(sys.stdin.readline().split())

    sol()
