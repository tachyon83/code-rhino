# -*- coding: utf-8 -*-
import sys
import copy
lab = []
viruslist = []
maxval = 0
n = m = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def getsafearea(copyed):
    safe = 0
    for i in range(n):
        for j in range(m):
            if copyed[i][j] == 0:
                safe +=1

    return safe

#dfs로 바이러스 퍼트리기
def spreadvirus(x, y, copyed):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0<= nx and nx < n and 0 <= ny and ny < m: #lab을 벗어나면 안됨
            if copyed[nx][ny] == 0:
                copyed[nx][ny] = 2
                spreadvirus(nx, ny, copyed)

#조합으로 벽 3개 놓는 모든 경우 구하기
def setwall(start, wall_cnt):
    global maxval

    if wall_cnt == 3:
        copyed = copy.deepcopy(lab) #벽이 세워진 lab

        for i in range(len(viruslist)):
            [cx, cy] = viruslist[i]
            spreadvirus(cx, cy, copyed)

        maxval = max(maxval, getsafearea(copyed))
        return

    for i in range(start, n*m):
        x = int(i/m)
        y = int(i%m)

        if lab[x][y] == 0:
            lab[x][y] = 1
            setwall(i+1, wall_cnt+1)
            lab[x][y] = 0

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())

    for i in range(n):
        lab.append(list(map(int, sys.stdin.readline().split())))

    for i in range(n):
        for j in range(m):
            if lab[i][j] == 2:
                viruslist.append([i, j])
    setwall(0,0)
    print(maxval)
