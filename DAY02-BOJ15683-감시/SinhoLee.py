n, m = map(int, input().split())

mat = [[*map(int, input().split())] for _ in range(n)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def fill(d, y, x, temp_mat):
    '''
    :param d: 방향
    :param x: cctv x좌표
    :param y: cctv y좌표
    :param temp_mat: cctv 전체공간을 deepcopy한 매트릭스
    :return: 감시공간을 채운 뒤의 매트릭스
    '''
    dd = d % 4  # adjust
    while True:
        ny, nx = y+dy[dd], x+dx[dd]
        if not (0 <= ny < n and 0 <= nx < m):
            break
        if temp_mat[ny][nx] == 6:
            break
        if temp_mat[ny][nx] == 0:
            temp_mat[ny][nx] = 9
        y, x = ny, nx

    return temp_mat


def cctv_1(d, y, x, temp_mat):
    return fill(d, y, x, temp_mat)


def cctv_2(d, y, x, temp_mat):
    temp_mat = fill(d, y, x, temp_mat)
    temp_mat = fill(d + 2, y, x, temp_mat)
    return temp_mat


def cctv_3(d, y, x, temp_mat):
    temp_mat = fill(d, y, x, temp_mat)
    temp_mat = fill(d + 1, y, x, temp_mat)
    return temp_mat


def cctv_4(d, y, x, temp_mat):
    temp_mat = fill(d, y, x, temp_mat)
    temp_mat = fill(d + 1, y, x, temp_mat)
    temp_mat = fill(d + 2, y, x, temp_mat)
    return temp_mat


def cctv_5(d, y, x, temp_mat):
    temp_mat = fill(d, y, x, temp_mat)
    temp_mat = fill(d + 1, y, x, temp_mat)
    temp_mat = fill(d + 2, y, x, temp_mat)
    temp_mat = fill(d + 3, y, x, temp_mat)
    return temp_mat


cctv_list = []
for i in range(n):
    for j in range(m):
        if 1 <= mat[i][j] < 6:
            cctv_list.append((i, j))

min_res = 64


def cnt_zero(mat):
    cnt = 0
    for i in range(n):
        for j in range(m):
           if mat[i][j] == 0:
               cnt += 1
    return cnt


def cctv(d, y, x, cctv_num, mat):
    temp_mat = [arr[:] for arr in mat]
    if cctv_num == 1:
        temp_mat = cctv_1(d, y, x, temp_mat)
    if cctv_num == 2:
        temp_mat = cctv_2(d, y, x, temp_mat)
    if cctv_num == 3:
        temp_mat = cctv_3(d, y, x, temp_mat)
    if cctv_num == 4:
        temp_mat = cctv_4(d, y, x, temp_mat)
    if cctv_num == 5:
        temp_mat = cctv_5(d, y, x, temp_mat)
    return temp_mat


def perm(depth, mat):
    global min_res
    if depth == -1:
        min_res = min(min_res, cnt_zero(mat))
        return

    for d in range(4):
        y, x = cctv_list[depth][0], cctv_list[depth][1]
        cctv_num = mat[y][x]
        perm(depth-1, cctv(d, y, x, cctv_num, mat))


perm(len(cctv_list)-1, mat)
print(min_res)

