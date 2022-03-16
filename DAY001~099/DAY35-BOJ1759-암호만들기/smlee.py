import sys 
from itertools import combinations

vowels = ['a', 'e', 'i', 'o', 'u']
L, C = map(int,input().split(' '))
pwd = sorted(input().split(' ')[:C]) 

comb = combinations(pwd, L)

for c in comb:
    cnt = 0
    for letter in c:
        if letter in vowels:
            cnt += 1

    if cnt >= 1 and cnt <= L-2:
        print(''.join(c))
