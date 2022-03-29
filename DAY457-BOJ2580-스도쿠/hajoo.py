def traverse(arr, x, y):
    if y >= 9:
        x += 1
        y = 0

    if x >= 9:
        for a in arr:
            print(*a)
        exit()

    if arr[x][y] == 0:
        for i in range(1, 10):
            if checkRowColumn(arr, x, y, i) and checkSquare(arr, x, y, i):
                arr[x][y] = i
                traverse(arr, x, y + 1)
                arr[x][y] = 0
    else:
        traverse(arr, x, y + 1)

def checkRowColumn(arr, x, y, n):
    for i in range(9):
        if arr[x][i] == n:
            return False
    for i in range(9):
        if arr[i][y] == n:
            return False
    return True

def checkSquare(arr, x, y, n):
    x = x // 3 * 3
    y = y // 3 * 3
    for i in range(x, x + 3, 1):
        for j in range(y, y + 3, 1):
            if arr[i][j] == n:
                return False
    return True

board = [list(map(int, input().split())) for _ in range(9)]

traverse(board, 0, 0)
