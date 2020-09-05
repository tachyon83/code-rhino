from copy import deepcopy
from itertools import permutations

# 사각지대 없애기
def make_light(office, direction, x, y):
    if not direction:
        return office
    
    N, M, V = len(office), len(office[0]), direction.pop()
    tmp_office = deepcopy(office)
    
    if V == 0: # 동
        for idx in range(M):
            if x + idx >= M or tmp_office[y][x + idx] == 6:
                break
            if tmp_office[y][x + idx] == 0:
                tmp_office[y][x + idx] = '#'
    elif V == 2: # 서
        for idx in range(M):
            if x - idx < 0 or tmp_office[y][x - idx] == 6:
                break
            if tmp_office[y][x - idx] == 0:
                tmp_office[y][x - idx] = '#'
    elif V == 1: # 남
        for idx in range(N):
            if y + idx >= N or tmp_office[y + idx][x] == 6:
                break
            if tmp_office[y + idx][x] == 0:
                tmp_office[y + idx][x] = '#'
    elif V == 3: # 북
        for idx in range(N):
            if y - idx < 0 or tmp_office[y - idx][x] == 6:
                break
            if tmp_office[y - idx][x] == 0:
                tmp_office[y - idx][x] = '#'

    return make_light(tmp_office, direction, x, y)
                

# 사각지대 카운트
def min_office(offices):
    ret = []
    for office in offices:
        cnt = 0
        for row in office:
            cnt += row.count(0)
        ret.append((office, cnt))
    return min(ret, key=lambda x: x[1])

def check(office, x, y, MIN):
    kind = office[y][x]
    offices = []
    if kind == 1:
        for v in range(4):
            offices.append(make_light(office, [v], x, y))
        office, MIN = min_office(offices)
    elif kind == 2:
        offices.append(make_light(office, [0, 2], x, y))
        offices.append(make_light(office, [1, 3], x, y))  
        office, MIN = min_office(offices)
    elif kind == 3:
        for v in range(4):
            offices.append(make_light(office, [v, v + 1], x, y))  
        office, MIN = min_office(offices)
    elif kind == 4:
        for v in range(4):
            tmp = [*range(4)]
            tmp.pop(v)
            offices.append(make_light(office, tmp, x, y))  
        office, MIN = min_office(offices)
    elif kind == 5:
        offices.append(make_light(office, [0,1,2,3], x, y))
        office, MIN = min_office(offices)
        
            
    return office, MIN


N, M = map(int, input().split())
office = [[0] * M for _ in range(N)]
MIN = float('inf')
cctv_pos = []

# 케이스 입력
for j in range(N):
    row = map(int, input().split())
    for idx, val in enumerate(row):
        office[j][idx] = val

        
# cctv 확인
for idx in range(N * M):
    y, x = divmod(idx, M)
    if office[y][x] in [1,2,3,4,5]:
        cctv_pos.append((x, y))
for cctvs in permutations(cctv_pos):
    tmp_office = deepcopy(office)
    for cctv in cctvs:
        x, y = cctv
        office, MIN = check(office, x, y, MIN)
        
print(MIN)
