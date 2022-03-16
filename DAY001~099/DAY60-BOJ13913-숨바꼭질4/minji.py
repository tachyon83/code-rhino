import sys
from collections import deque

def sol():
    maps[n][0] = 0 # time
    q = deque([n])
    ans = [k]
    pre = k
    while q:
        x = q.popleft()
        for nx in [x+1, x-1, 2*x]:
            if 0 <= nx < 100001 and maps[nx][0] == -1:
                q.append(nx)
                maps[nx][0] = maps[x][0] + 1
                maps[nx][1] = x

    while maps[pre][1] != -1:
        ans.append(maps[pre][1])
        pre = maps[pre][1]
    ans.reverse()
    print(maps[k][0])
    print(' '.join(map(str, ans)))

if __name__ == "__main__":
    n, k = list(map(int, sys.stdin.readline().split()))
    maps = [[-1]*2 for _ in range(100001)]
    sol()
