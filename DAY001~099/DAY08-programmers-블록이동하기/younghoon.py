from collections import deque

def get_next_pos(pos, board):
    next_pos = []
    pos = list(pos)
    pos1x, pos1y, pos2x, pos2y = pos[0][0], pos[0][1], pos[1][0], pos[1][1]
    dx = [-1, 1, 0, 0] # dx
    dy = [0, 0, -1, 1] # dy
    for i in range(4): #갈수있는곳 4방향 탐색
        if board[pos1x+dx[i]][pos1y+dy[i]] == 0 and board[pos2x+dx[i]][pos2y+dy[i]] == 0:
            next_pos.append({((pos1x+dx[i]),(pos1y+dy[i])), ((pos2x+dx[i]),(pos2y+dy[i]))})
    for i in [-1, 1]: 
        if pos1x == pos2x: #가로로 위치해있을때 세로로 회전하는 경우 2가지, 2블록을 체크하는 이유: 어짜피 인접 2블록중 1블록이라도 차있으면 회전 못함
            if board[pos1x + i][pos1y] == 0 and board[pos2x + i][pos2y] == 0: 
                next_pos.append({(pos1x, pos1y), (pos1x + i, pos1y)})
                next_pos.append({(pos2x, pos2y), (pos2x + i, pos2y)})
        elif pos1y == pos2y: #세로로 위치해있을때 가로로 회전하는 경우 2가지, 2블록을 체크하는 이유: 어짜피 인접 2블록중 1블록이라도 차있으면 회전 못함
            if board[pos1x][pos1y + i] == 0 and board[pos2x][pos2y + i] == 0: 
                next_pos.append({(pos1x, pos1y), (pos1x, pos1y + i)})
                next_pos.append({(pos2x, pos2y), (pos2x, pos2y + i)})
    return next_pos

def solution(board):

    n = len(board)
    new_board = [[1]*(n+2) for _ in range(n+2)]
    #패딩 만들기, 보드의 좌우양옆 1의 벽 만들기
    for i in range(len(board)):
        for j in range(len(board)):
            new_board[i+1][j+1] = board[i][j]
    queue = deque()
    visited = []
    pos = {(1,1),(1,2)}
    queue.append((pos, 0))
    visited.append(pos)
    while queue:
        pos, cost = queue.popleft()
        #최단거리 탐색완료
        if (n,n) in pos: 
            return cost
        for next_pos in get_next_pos(pos, new_board):
            if next_pos not in visited:
                visited.append(next_pos)
                queue.append((next_pos, cost+1))
    return 0
