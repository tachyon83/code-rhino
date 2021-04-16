import sys
si = sys.stdin.readline

abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
n, m = [int(e) for e in si().split()]
pokemons1 = dict()
pokemons2 = dict()

for i in range(n):
    name = si()[:-1]
    pokemons1[i+1] = name
    pokemons2[name] = i+1

for _ in range(m):
    curr = si()[:-1]
    if curr[0] in abc:
        print(pokemons2[curr])
    else:
        print(pokemons1[int(curr)])
