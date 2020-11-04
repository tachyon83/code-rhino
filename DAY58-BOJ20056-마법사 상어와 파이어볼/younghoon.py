import sys
from collections import defaultdict
#sys.stdin = open('input.txt', 'r')
N, M, K = map(int, sys.stdin.readline().split())
# row col mass speed dir
fireballs = list(list(map(int, sys.stdin.readline().split())) for _ in range(M))
grid = [[0] * (N) for _ in range(N)]

xdir = [-1,-1,0,1,1,1,0,-1]
ydir = [0,1,1,1,0,-1,-1,-1]

fireballs_dict = defaultdict(list)
for fireball in fireballs:
    x, y, mass, speed, dir = fireball
    fireballs_dict[(x-1, y-1)].append([mass, speed, dir])

def is_all_even(l):
    for val in l:
        if val % 2 != 0:
            return False
    return True
def is_all_odd(l):
    for val in l:
        if val % 2 == 0:
            return False
    return True
for _ in range(K):
    new_balls = defaultdict(list)
    for key, values in fireballs_dict.items():
        x,y = key
        for ball in values:
            mass, speed, dir = ball
            nx = (x + xdir[dir] * speed)%N
            ny = (y + ydir[dir] * speed)%N
            new_balls[(nx,ny)].append([mass, speed, dir])
    zero_mass = set()
    for key, values in new_balls.items():
        x, y = key
        if len(new_balls[key]) > 1:
            mass = 0
            speed = 0
            dir = []
            for value in values:
                mass += value[0]
                speed += value[1]
                dir.append(value[2])
            mass //= 5
            speed //= len(new_balls[key])
            if mass == 0:
                zero_mass.add((x,y))
            if is_all_even(dir) or is_all_odd(dir):
                new_balls[(x,y)] = [[mass,speed,0],[mass,speed,2],[mass,speed,4],[mass,speed,6]]
            else:
                new_balls[(x,y)] = [[mass,speed,1], [mass,speed,3], [mass,speed,5], [mass,speed,7]]
    for to_remove in zero_mass:
        new_balls.pop(to_remove)
    fireballs_dict = new_balls

result = 0
for values in fireballs_dict.values():
    for value in values:
        result += value[0]
print(result)







