import sys
from collections import deque
from itertools import combinations as cb
si = sys.stdin.readline


def main():
    n, m = [int(e) for e in si().split()]
    board, chains, num, chainList, mn, houses = [], dict(), 1, [], (n+n+1)*n, []
    for i in range(n):
        temp = [int(e) for e in si().split()]
        board.append(temp)
        for j in range(n):
            if temp[j] == 2:
                chains[num] = (i, j)
                chainList.append(num)
                num += 1
            elif temp[j] == 1:
                houses.append((i, j))

    dr, dc = [0, 1, 0, -1], [1, 0, -1, 0]
    cost = [[[] for _ in range(n)]for _ in range(n)]
    for chain in chainList:
        visited = [[False for _ in range(n)]for _ in range(n)]
        visited[chains[chain][0]][chains[chain][1]] = True
        q, d = deque(), 0
        q.append(chains[chain])
        while q:
            d += 1
            qs = len(q)
            for _ in range(qs):
                curr = q.popleft()
                for idx in range(4):
                    nr, nc = curr[0]+dr[idx], curr[1]+dc[idx]
                    if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
                        cost[nr][nc].append(d)
                        visited[nr][nc] = True
                        q.append((nr, nc))

    pos = cb(chainList, m)
    for choice in pos:
        effcost = [[(n+n+1)*n for _ in range(n)]for _ in range(n)]
        for e in choice:
            for house in houses:
                effcost[house[0]][house[1]] = min(
                    effcost[house[0]][house[1]], cost[house[0]][house[1]][e-1])

        chickendist = 0
        for house in houses:
            chickendist += effcost[house[0]][house[1]]
        mn = min(mn, chickendist)
    print(mn)


if __name__ == '__main__':
    main()
