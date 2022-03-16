from collections import deque
import sys

input = sys.stdin.readline

n, k = map(int, input().split())
a = list(map(int, input().split()))
c = [0] * (2*n)
robot = deque()
cnt = 0

while True:
    cnt += 1
    a = a[-1:] + a[:-1]
    c = c[-1:] + c[:-1]
    if c[len(c) // 2 - 1]:
        c[len(c) // 2 - 1] = 0

    qlen = len(robot)
    for _ in range(qlen):
        rx = robot.popleft()
        rx += 1
        if rx == len(a) // 2 - 1:
            continue
        nx = rx + 1
        if not c[nx] and a[nx] > 0:
            if nx == len(a) // 2 - 1:
                c[rx] = 0
            else:
                robot.append(nx)
                c[rx], c[nx] = 0, 1
            a[nx] -= 1
        else:
            robot.append(rx)

    if a[0] > 0 and not c[0]:
        robot.append(0)
        c[0] = 1
        a[0] -= 1

    if a.count(0) >= k:
        break

print(cnt)
