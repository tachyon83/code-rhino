import sys
from collections import deque
si = sys.stdin.readline


def main():
    n, k = [int(e) for e in si().split()]
    A = [int(e) for e in si().split()]
    t, q, up, down = 0, deque(), 0, n-1
    occupied = [False for _ in range(2*n)]

    def cntzero():
        nonlocal A
        cnt = 0
        for e in A:
            if not e:
                cnt += 1
        return cnt

    while True:
        t += 1
        up, down = up-1, down-1
        if up < 0:
            up = 2*n-1
        if down < 0:
            down = 2*n-1

        qs = len(q)
        for _ in range(qs):
            curr = q.popleft()
            if curr == down:
                occupied[curr] = False
                continue
            nx = curr+1
            if nx == 2*n:
                nx = 0
            if not occupied[nx] and A[nx]:
                occupied[curr] = False
                A[nx] -= 1
                if nx == down:
                    continue
                occupied[nx] = True
                q.append(nx)
                continue
            q.append(curr)

        if A[up]:
            occupied[up] = True
            A[up] -= 1
            q.append(up)

        if cntzero() >= k:
            print(t)
            break


if __name__ == '__main__':
    main()
