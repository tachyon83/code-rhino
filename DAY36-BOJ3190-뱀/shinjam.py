N, K = int(input()), int(input()) # N: 보드크기, K: 사과 갯수
# 사과 위치 값
apples_pos = {tuple(map(lambda x: int(x)-1, input().split())) for _ in range(K)}
L = int(input()) # L: 뱀의 방향 변환 횟수
# 뱀 변화 시각, 방향
directions = dict(map(lambda x: int(x) if x.isdigit() else x, input().split()) for _ in range(L))

# 현재 방향으로 계속 이동
    # 1. 벽 이거나 자기 몸이면(방문했으면) 탈출
    # 2. 사과 있으면 꼬리 냅두기, 없으면 꼬리 지우기
    # 3. 시간 + 1
    # 4. 방향 전환해야 하면 방향 전환
time = 0
dx, dy = (1, 0, -1, 0), (0, 1, 0, -1) # 0~3: 동남서북
body_pos, v = [(0, 0)], 0 # 지렁이 좌표, 방향
while True:
    new_x, new_y = body_pos[-1][0] + dx[v], body_pos[-1][1] + dy[v]
    if not all(0<=p<N for p in [new_x, new_y]): # 1 벽
        break
    if (new_x, new_y) in body_pos: # 1 자기 몸
        break
    body_pos.append((new_x, new_y))
    if (new_y, new_x) not in apples_pos: # 2 
        body_pos.pop(0)
    else:
        apples_pos.remove((new_y, new_x))
    
    time += 1 # 3
    new_v = directions.get(time, False) # 4
    if new_v == 'D':
        v = (v + 1) % 4
    elif new_v == 'L':
        v = (v - 1) % 4
print(time + 1)
