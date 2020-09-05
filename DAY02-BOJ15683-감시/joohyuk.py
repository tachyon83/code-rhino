import sys
import copy
si = sys.stdin.readline

cctv = dict()
dx, dy = [0, 1, 0, -1], [-1, 0, 1, 0]


def findzones(board):
    bz = 0
    for i in range(len(board)):
        for j in range(len(board[0])):
            if not board[i][j]:
                bz += 1
    return bz


def blindzone(k, board, cctv_cnt, mn):
    global dx, dy
    if k == cctv_cnt:
        mn = min(mn, findzones(board))
        return mn

    kind, currx, curry = cctv[k][0], cctv[k][1][0], cctv[k][1][1]

    if kind == 1:
        for i in range(4):
            boardcopy = copy.deepcopy(board)
            dxt, dyt = dx[i], dy[i]
            nx = currx+dxt
            ny = curry+dyt
            while 0 <= nx < len(board) and 0 <= ny < len(board[0]) and boardcopy[nx][ny] != 6:
                if not boardcopy[nx][ny]:
                    boardcopy[nx][ny] = -1
                nx += dxt
                ny += dyt
            mn = min(mn, blindzone(k+1, boardcopy, cctv_cnt, mn))

    if kind == 2:
        for i in range(2):
            boardcopy = copy.deepcopy(board)
            for j in range(2):
                dxt, dyt = dx[i+2*j], dy[i+2*j]
                nx = currx+dxt
                ny = curry+dyt
                while 0 <= nx < len(board) and 0 <= ny < len(board[0]) and boardcopy[nx][ny] != 6:
                    if not boardcopy[nx][ny]:
                        boardcopy[nx][ny] = -1
                    nx += dxt
                    ny += dyt
            mn = min(mn, blindzone(k+1, boardcopy, cctv_cnt, mn))

    if kind == 3:
        for i in range(4):
            boardcopy = copy.deepcopy(board)
            for j in range(2):
                dxt, dyt = dx[(i+j) % 4], dy[(i+j) % 4]
                nx = currx+dxt
                ny = curry+dyt
                while 0 <= nx < len(board) and 0 <= ny < len(board[0]) and boardcopy[nx][ny] != 6:
                    if not boardcopy[nx][ny]:
                        boardcopy[nx][ny] = -1
                    nx += dxt
                    ny += dyt
            mn = min(mn, blindzone(k+1, boardcopy, cctv_cnt, mn))

    if kind == 4:
        for i in range(4):
            boardcopy = copy.deepcopy(board)
            for j in range(3):
                dxt, dyt = dx[(i+j) % 4], dy[(i+j) % 4]
                nx = currx+dxt
                ny = curry+dyt
                while 0 <= nx < len(board) and 0 <= ny < len(board[0]) and boardcopy[nx][ny] != 6:
                    if not boardcopy[nx][ny]:
                        boardcopy[nx][ny] = -1
                    nx += dxt
                    ny += dyt
            mn = min(mn, blindzone(k+1, boardcopy, cctv_cnt, mn))

    if kind == 5:
        boardcopy = copy.deepcopy(board)
        for i in range(4):
            dxt, dyt = dx[i], dy[i]
            nx = currx+dxt
            ny = curry+dyt
            while 0 <= nx < len(board) and 0 <= ny < len(board[0]) and boardcopy[nx][ny] != 6:
                if not boardcopy[nx][ny]:
                    boardcopy[nx][ny] = -1
                nx += dxt
                ny += dyt
        mn = min(mn, blindzone(k+1, boardcopy, cctv_cnt, mn))

    return mn


def main():
    n, m = [int(e) for e in si().split()]
    mn, board, k, wallcnt = 8*8+1, [], 1, 0
    for i in range(n):
        l = [int(e) for e in si().split()]
        for j in range(m):
            if 0 < l[j] < 6:
                cctv[k] = (l[j], (i, j))
                k += 1
            elif l[j] == 6:
                wallcnt += 1
        board.append(l)

    if k == 1:
        print(n*m-wallcnt)
        return

    boardcopy = copy.deepcopy(board)
    print(blindzone(1, boardcopy, k, mn))


if __name__ == '__main__':
    main()
