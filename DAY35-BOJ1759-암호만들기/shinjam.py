from itertools import combinations


L, C = map(int, input().split())
chars = list(input().split())

ret = []
for x in combinations(chars, L):
    check = set(x) - {'a', 'e', 'i', 'o', 'u'}
    if len(check) < len(x) and len(check) >= 2:
        ret.append(sorted(x))
for x in sorted(ret):
    print(''.join(x))
