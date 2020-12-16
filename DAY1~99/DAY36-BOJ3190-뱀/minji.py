import sys

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def sol(maps):

    d_len = 1
    k = int(sys.stdin.readline())

    for i in range(k):
        y, x = map(int, sys.stdin.readline().split())
        maps[y - 1][x - 1] = -1

    d_y = d_x = 0
    curr_time = 0
    d_dir = 1

    l = int(sys.stdin.readline())
    sec, dir = sys.stdin.readline().split()
    l-=1

    while True:
        #print("curr_time: ", curr_time, "y: ", d_y, "x: ", d_x, "dir :", d_dir)
        if curr_time == int(sec):
            if dir == "L":
                d_dir = (d_dir+1) % 4
            else:
                d_dir = (d_dir-1) % 4

            if (l > 0):
                sec, dir = sys.stdin.readline().split()
                l -= 1

        d_y = d_y + dy[d_dir]
        d_x = d_x + dx[d_dir]

        curr_time += 1

        if 0 > d_x or d_x >= n or 0 > d_y or d_y >= n:
            print(curr_time)
            return
        #self
        if (maps[d_y][d_x] > 0 and maps[d_y][d_x] >= curr_time - d_len):
            print(curr_time)
            return
        #apple
        if maps[d_y][d_x] == -1:
            d_len += 1

        maps[d_y][d_x] = curr_time
    return


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    maps = [[0] * n for _ in range(n)]

    sol(maps)
