

import sys
from itertools import combinations
#sys.stdin = open("input.txt", "r")
L, C = map(int, sys.stdin.readline().split())
chars = list(sys.stdin.readline().split())
chars.sort()

all_outputs = list(combinations(chars,L))
vowls = ['a', 'e', 'i', 'o', 'u']

for case in all_outputs:
    v_count = 0
    for char in case:
        if char in vowls:
            v_count += 1
    if v_count>= 1 and len(case) - v_count >= 2:
       print(''.join(case))
