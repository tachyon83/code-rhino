import sys
from collections import deque
si = sys.stdin.readline


def main():
    [n, t] = [int(e) for e in si().split()]
    l = [int(e) for e in si().split()]
    cnt, q = 0, deque()
    q.append((0, 0))
    q.append((l[0], 0))
    if l[0] == t:
        cnt += 1
    while q:
        curr = q.popleft()
        if curr[1]+1 < n:
            if curr[0]+l[curr[1]+1] == t:
                cnt += 1
            q.append((curr[0]+l[curr[1]+1], curr[1]+1))
            q.append((curr[0], curr[1]+1))
    print(cnt)


if __name__ == '__main__':
    main()
