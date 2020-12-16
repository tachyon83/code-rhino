'''
핵심 컨샙은,
1) 로봇이 두칸을 차지하고 있기 때문에, 관심을 갖는 좌표와 그 좌표 기준으로
어느 방향을 향하고 있는지를  확인하여 두 칸을 판단하는 것
2) 상하좌우 `회전하지 않고` 움직이는 이동양식과 로봇이 두 칸을 차지할 때, 각각의 칸을 기준으로
시계방향, 반시계방향으로 회전한다는 것

'''

def solution(board):
        # 상 우 하 좌 -> 시계방향, 반시계방향 회전을 고려할때 보통 연속되는 회전을 미리 저장하여 d+1, d-1로 회전을 제어한다.
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    n = len(board)
    visited = [[[0, 0, 0, 0] for _ in range(n)] for _ in range(n)]

    # cnt, d, y, x
    queue = [(0, 1, 0, 0)]
    visited[0][0][1] = -1  # base mark
    while queue:
        cnt, d, y, x = queue.pop(0)

        if (y == n - 1 and x == n - 1) or (y + dy[d] == n - 1 and x + dx[d] == n - 1):
            break
        for k in range(4):  # 상우하좌
            ny, nx = y + dy[k], x + dx[k]
            nny, nnx = y + dy[d] + dy[k], x + dx[d] + dx[k]  # 기준의 옆
            if not (0 <= ny < n and 0 <= nx < n):  # 로봇기준이 바깥에 나가는지 체크
                continue
            if not (0 <= nny < n and 0 <= nnx < n):  # 로봇기준 옆이 바깥에 나가는지 체크
                continue
            if board[ny][nx] or board[nny][nnx]:  # 로봇과 겹치는 벽이 있는지 체크
                continue
            if visited[ny][nx][d]:
                continue
            visited[ny][nx][d] = cnt+1
            queue.append((cnt + 1, d, ny, nx))

        for k in [1, -1]:  # 시계방향, 반시계방향 회전
            ny, nx = y, x # 회전축 기준
            nny, nnx = y + dy[(d+k) % 4], x + dx[(d+k)%4]  # 회전축을 중심으로 현재 바라보는 방향에서 시계방향 or 반시계 방향으로 회전
            if (0 <= ny < n and 0 <= nx < n) and (0 <= nny < n and 0 <= nnx < n):  # 로봇기준이 바깥에 나가는지 체크
                if not (board[nny][nnx] or board[nny + dy[d]][nnx + dx[d]]):  # 로봇이 회전할 때, 벽이 있는지 체크
                    if not visited[ny][nx][(d+k)%4]:
                        visited[ny][nx][(d+k)%4] = cnt+1
                        queue.append((cnt+1, (d+k)%4, ny, nx))
            # 회전축 다른 축으로 변경
            ny, nx = y + dy[d], x + dx[d]
            nny, nnx = y + dy[(d+k) % 4] + dy[d], x + dx[(d+k)%4] + dx[d]
            if (0 <= ny < n and 0 <= nx < n) and (0 <= nny < n and 0 <= nnx < n):  # 로봇기준이 바깥에 나가는지 체크
                # 회전축이 변경되었으므로 회전가능한지 체크하는 계산로직 변경
                if not (board[y + dy[(d+k) % 4]][x + dx[(d+k)%4]] or board[nny][nnx]):
                    if not visited[ny][nx][(d+k)%4]:
                        visited[ny][nx][(d+k)%4] = cnt+1
                        queue.append((cnt+1, (d+k)%4, ny, nx))

    return cnt


print(solution([[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]))