from collections import deque


def solution(N, number):
    vis, q = set(), deque()
    vis.add(N)
    q.append([N, 1])

    while q:
        qs = len(q)
        for _ in range(qs):
            curr, cnt = q.popleft()
            if cnt > 8:
                return -1
            if curr == number:
                return cnt

            nxArr = []
            nxArr.append(int(str(curr)+str(N)))
            nxArr.append(curr+N)
            nxArr.append(curr-N)
            nxArr.append(curr*N)
            nxArr.append(curr//N)

            for nx in nxArr:
                if nx not in vis:
                    vis.add(nx)
                    q.append([nx, cnt+1])
