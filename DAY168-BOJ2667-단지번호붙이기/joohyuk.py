from collections import deque
import sys
si = sys.stdin.readline

directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
visited = set()


def DFS(g, r, c, n):
    visited.add((r, c))
    node = 1
    for direction in directions:
        rn, cn = r+direction[0], c+direction[1]
        if not (rn >= n or rn < 0 or cn >= n or cn < 0 or (rn, cn) in visited or int(g[rn][cn]) == 0):
            node += DFS(g, rn, cn, n)
    return node


def main():
    n = int(si())
    board = [si()[:-1] for _ in range(n)]
    comp, nodes = 0, []
    for r in range(n):
        for c in range(n):
            if int(board[r][c]) == 1 and (r, c) not in visited:
                comp += 1
                nodes.append(DFS(board, r, c, n))

    print(comp)
    nodes.sort()
    for i in range(len(nodes)):
        print(nodes[i])
    return


if __name__ == '__main__':
    main()
