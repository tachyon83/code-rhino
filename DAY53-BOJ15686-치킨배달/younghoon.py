import sys, itertools
#sys.stdin = open('input.txt', 'r')
N, M = map(int, sys.stdin.readline().split())

chicken_place = []
for _ in range(N):
    chicken_place.append(list(map(int, sys.stdin.readline().split())))

homes = set()
chickens = set()
for i in range(N):
    for j in range(N):
        if chicken_place[i][j] == 1:
            homes.add((i,j))
        if chicken_place[i][j] == 2:
            chickens.add((i,j))
chicken_combination = (list(itertools.combinations(chickens, M)))

total_set = []
for comb in chicken_combination:
    dist = 0
    for home in homes:
        home_to_chicken = sys.maxsize
        for chicken in comb:
            home_to_chicken = min(home_to_chicken, abs(chicken[0] - home[0]) + abs(chicken[1] - home[1]))
        dist+=home_to_chicken
    total_set.append(dist)
print(min(total_set))


