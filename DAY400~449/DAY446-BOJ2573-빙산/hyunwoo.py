# 그래프 탐색 문제
# 최적화 없이 난잡하게 구현해서 코드 개선의 여지 있음

import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
q = deque([])
i = 0
isNull = True

n, m = map(int, sys.stdin.readline().split())
li = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# [a, b]점에 대한 빙하 덩어리 BFS 탐색 
def bfs(a, b):
    q.append([a, b])
    while q:
        x, y = q.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if li[nx][ny] != 0 and visited[nx][ny] == False:
                    visited[nx][ny] = True
                    q.append([nx, ny])

while True:
    # chk : 빙하 값이 0이 아닐 때 상하좌우로 바닷물과 접하는 면의 수
    # visited : BFS 탐색 시 방문한 빙하 좌표
    # count : 빙하 덩어리 개수
    # isNull : 빙하가 모두 녹았는지 아닌지 체크하는 변수
    # i : 빙하를 녹인 년수
    chk = [[0 for _ in range(m)] for __ in range(n)]
    visited = [[False for _ in range(m)] for __ in range(n)]
    count = 0
    isNull = True
    
    # 빙하 값이 0이 아닐 때 해당 지점부터 BFS 탐색으로 덩어리 찾기, 덩어리 개수 += 1
    for j in range(n):
        for k in range(m):
            if li[j][k] != 0 and visited[j][k] == False:
                bfs(j, k)
                count += 1
    
    # 덩어리 개수가 2개 이상일 때 빙하를 녹인 년수를 출력 후 프로그램 종료
    if count > 1:
        print(i)
        exit(0)
    
    # 빙하 주변으로 접하는 바닷물 면수 갱신
    for j in range(n):
        for k in range(m):
            for l in range(4):
                if 0 <= j + dx[l] < n and 0 <= k + dy[l] < m:
                    if li[j + dx[l]][k + dy[l]] == 0:
                        chk[j][k] += 1
    # 위에서 구한 chk를 빙하에서 빼서 녹은 후 높이를 계산
    # 하나라도 녹을 게 남아있을 시 isNull을 False로
    for j in range(n):
        for k in range(m):
            if li[j][k] != 0:
                li[j][k] = max(0, li[j][k] - chk[j][k])
                isNull = False
    
    # 더 이상 녹을 게 하나도 남아있지 않을 시 루프 탈출
    # 녹인 년수 갱신
    if isNull:
        break
    i += 1

# 마지막까지 한 덩어리로 유지하고 녹아서 루프문을 탈출 시 0 
print(0)
