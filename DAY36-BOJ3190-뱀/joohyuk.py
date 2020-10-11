import sys
from collections import deque
si = sys.stdin.readline

apples, dq, snake, board = set(), deque(), deque(), []


def change_direction(direction):
    global dq
    if dq[0][1] == 'L':
        return (direction+1) % 4
    direction -= 1
    if direction < 0:
        direction = 3
    return direction


def willCrash(r, c, n):
    global board
    if not (0 <= r < n and 0 <= c < n):
        return True
    if board[r][c]:
        return True
    return False


def isApple(r, c):
    global apples
    if (r, c) in apples:
        apples.remove((r, c))
        return True
    return False


def main():
    global apples, dq, snake, board
    n = int(si())  # board size
    board = [[0 for _ in range(n)]for _ in range(n)]
    k = int(si())  # apples
    while k:
        k -= 1
        r, c = [int(e) for e in si().split()]
        apples.add((r-1, c-1))
    l = int(si())
    while l:
        l -= 1
        x, c = [e for e in si().split()]
        dq.append((int(x), c))

    t, direction, dr, dc, cr, cc = 0, 0, [0, -1, 0, 1], [1, 0, -1, 0], 0, 0

    while not willCrash(cr, cc, n):
        if dq and dq[0][0] == t:
            direction = change_direction(direction)
            dq.popleft()
        t += 1
        board[cr][cc] = 1
        snake.append((cr, cc))
        if t > 1 and not isApple(cr, cc):
            lr, lc = snake.popleft()
            board[lr][lc] = 0
        cr, cc = cr+dr[direction], cc+dc[direction]

    print(t)


if __name__ == '__main__':
    main()
