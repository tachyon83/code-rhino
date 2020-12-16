import sys
from itertools import combinations

vowels = ['a', 'e', 'i', 'o', 'u']
L, C = map(int, sys.stdin.readline().split())
pwd = sorted(list(map(str, sys.stdin.readline().split())))

comb = combinations(pwd, L)

for c in comb:
    count = 0
    for letter in c:
        if letter in vowels:
            count += 1

    if (count >= 1) and (count <= L-2):
        print(''.join(c))
