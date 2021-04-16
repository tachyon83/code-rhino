import sys
from collections import deque
si = sys.stdin.readline


def main():
    n = int(si())
    r = [si()[:-1] for _ in range(n)]
    cnt = [0 for _ in range(n)]
    for i in range(n):
        visited = [False for _ in range(n)]
        q = deque()
        q.append(i)
        qs = 1
        visited[i] = True
        depth, f = 0, 0
        while depth < 2:
            depth += 1
            sz = qs
            for _ in range(sz):
                curr = q.popleft()
                qs -= 1
                for idx, e in enumerate(r[curr]):
                    if e == 'Y' and not visited[idx]:
                        visited[idx] = True
                        f += 1
                        q.append(idx)
                        qs += 1
        cnt[i] = f
    print(max(cnt))


if __name__ == '__main__':
    main()
