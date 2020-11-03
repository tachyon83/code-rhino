# -*- coding: utf:8 -*-
from collections import deque
import sys

def sol():
    ans = 1
    robot = deque([0] * (n * 2))
    while True:
        # 1
        a.rotate(1)
        robot.rotate(1)
        robot[n - 1] = 0

        #2
        for i in range(n-2, -1, -1):
            if (robot[i] != 0 and robot[i+1] == 0 and a[i+1] >= 1):
                a[i+1] -= 1
                robot[i+1] = robot[i]
                robot[i] = 0
        robot[n-1] = 0

        #3
        if (robot[0] == 0 and a[0] > 0):
            a[0] -= 1
            robot[0] = 1

        #4
        if a.count(0) >= k:
            return ans
        ans += 1

if __name__ == "__main__":
    n, k = list(map(int, sys.stdin.readline().split()))
    a = deque(map(int, sys.stdin.readline().split()))
    print(sol())
