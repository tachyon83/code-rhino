import sys
import copy
si = sys.stdin.readline

abc, sv, board = set(), 26, []
for e in 'ABCDEFGHIJKL':abc.add(e)

scores = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0}
checkpoints = {
    5: [4],
    8: [3, 4],
    11: [1, 2, 3, 4],
    12: [1, 2, 3, 4, 5, 6],
}
pointsGroup = {
    1: {1, 4, 7, 11},
    2: {8, 9, 10, 11},
    3: {1, 3, 6, 8},
    4: {2, 3, 4, 5},
    5: {5, 7, 10, 12},
    6: {2, 6, 9, 12},
}
pointsMap = {
    1: (0, 4),
    2: (1, 1),
    3: (1, 3),
    4: (1, 5),
    5: (1, 7),
    6: (2, 2),
    7: (2, 6),
    8: (3, 1),
    9: (3, 3),
    10: (3, 5),
    11: (3, 7),
    12: (4, 4),
}


def process(pn, e, mode):
    global abc, board, pointsMap, pointsGroup, scores
    i, j = pointsMap[pn]
    if mode:
        abc.remove(e)
        board[i][j] = e
    else:
        abc.add(e)
        board[i][j] = 'x'

    for gr in pointsGroup.keys():
        if pn in pointsGroup[gr]:
            v=ord(e)-ord('A')+1
            if mode:scores[gr] +=v
            else:scores[gr] -=v


for i in range(5):
    temp = si()[:-1]
    row = []
    for e in temp:row.append(e)
    board.append(row)
for idx in range(1, 12+1):
    i, j = pointsMap[idx]
    if board[i][j] != 'x':
        abc.remove(board[i][j])
        for gr in pointsGroup.keys():
            if idx in pointsGroup[gr]:scores[gr] += (ord(board[i][j])-ord('A')+1)


def check(n):
    global scores, checkpoints, sv
    if n in checkpoints:
        for ln in checkpoints[n]:
            if scores[ln] != sv:return False
    return True


def dfs(pn):
    global board, sv, abc, pointsGroup, pointsMap
    if pn == 12+1:return True
    i, j = pointsMap[pn]
    if board[i][j] != 'x':
        if not check(pn):return False
        return dfs(pn+1)
    abcCurr = list(copy.deepcopy(abc))
    abcCurr.sort()
    for e in abcCurr:
        process(pn, e, 1)
        if not check(pn):process(pn, e, 0)
        else:
            if not dfs(pn+1):process(pn, e, 0)
            else:return True
    return False


dfs(1)
for row in board:
    for c in row:print(c, end='')
    print()
