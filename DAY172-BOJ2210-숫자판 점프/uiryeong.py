from sys import stdin
import sys
sys.setrecursionlimit(100000)

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]

ret = set()
def dfs(r, c, depth, n):

    if depth == 6:
        ret.add(n)
        return

    for i in range(4):
        mapr = r + dr[i]
        mapc = c + dc[i]
        if mapr >= 0 and mapc >= 0 and mapr < 5 and mapc < 5:
            dfs(mapr, mapc, depth+1, n * 10 + digit_map[mapr][mapc])


input = stdin.readline
map_size = 5
digit_map = [list(map(int, input().split())) for _ in range(map_size)]

for i in range(map_size):
    for j in range(map_size):
        dfs(i, j, 1, digit_map[i][j])

print(len(ret))
