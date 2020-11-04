import sys
from collections import deque
#sys.stdin = open('input.txt', 'r')
N, K = map(int, sys.stdin.readline().split())
conv = deque(map(int, sys.stdin.readline().split()))
time = 0
robot = deque([0] * (2 * N))

while conv.count(0) < K:
    time += 1
    conv.rotate(1)
    robot.rotate(1)
    robot[N-1] = 0

    # 로봇을 한칸씩 밀어준다
    for i in range(N):
        if(conv[N-1-i] != 0 and robot[N-2-i] != 0 and robot[N-1-i] == 0):
            conv[N-1-i] -= 1
            robot[N-1-i] = robot[N-2-i]
            robot[N-2-i] = 0
    robot[N-1] = 0

    # 로봇을 올려준다
    if robot[0] == 0 and conv[0] > 0:
        conv[0] -= 1
        robot[0] = 1

print(time)



