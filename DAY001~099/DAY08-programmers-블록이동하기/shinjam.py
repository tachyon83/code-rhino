from collections import deque
    

def bfs(board, visited, N):
    dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
    queue = deque([(1, 1, 0, 0)]) # x, y, 방향, 시간
    ret = []
    
    while queue:
        x1, y1, direction, time = queue.popleft()
        x2, y2 = x1 + dx[direction], y1 + dy[direction]
        
        
        # Skip
        if 0 in [x1,y1,x2,y2] or N + 1 in [x1,y1,x2,y2]: ## 인덱스
            continue
        if 1 in [board[y1][x1], board[y2][x2]]: ## 벽
            continue
        if {(x1, y1), (x2, y2)} in visited: ## 이미 방문
            continue
            
        # 정답
        if (N, N) in [(x1, y1), (x2, y2)]:
            ret.append(time)
            continue
            
        visited.append({(x1, y1), (x2, y2)})

        # 이동
        for v in range(4):
            queue.append((x1 + dx[v], y1 + dy[v], direction, time + 1))
        
        # 회전
        if direction % 2: # 세로 방향일 때
            if not board[y1 + 1][x1 - 1]:
                queue.append((x1, y1, 2, time))
            if not board[y1 + 1][x1 + 1]:
                queue.append((x1, y1, 0, time))
        else: # 가로 방향일 때
            if not board[y1 - 1][x1 + 1]:
                queue.append((x1, y1, 3, time))
            if not board[y1 + 1][x1 + 1]:
                queue.append((x1, y1, 1, time))
            
    return min(ret)
        
    
def solution(board):
    N = len(board)
    large_board = [[1] * (N +2) for _ in range(N + 2)]
    for idx in range(N * N):
        i, j = divmod(idx, N)
        large_board[i + 1][j + 1] = board[i][j]

    return bfs(large_board, [], N)
    
